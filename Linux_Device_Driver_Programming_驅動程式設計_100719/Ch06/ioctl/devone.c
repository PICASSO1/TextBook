
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build120718
 *
 * Date: 2018 / 12 / 07
 *
 * Description: 
 * 1. 這一支Kernal Space的程序，展現了ioctl()的用法。
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

#include <linux/sched.h>
#include <asm/current.h>

MODULE_LICENSE("Dual BSD/GPL");

static int devone_devs = 1;
static int devone_major = 0;
static int devone_minor = 0;
module_param(devone_major, uint, 0);
struct cdev devone_cdev;
static struct class *devone_class = (struct class *)NULL;

struct devone_data {
	rwlock_t lock;
	unsigned char val;
};

int devone_open(struct inode *indoe, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)NULL;

	dev = (struct devone_data *)kmalloc(sizeof(struct devone_data), GFP_KERNEL);
	if (dev == (struct devone_data *)NULL)
		return -ENOMEM;

	rwlock_init(&dev->lock);
	dev->val = 0xFF;

	filp->private_data = (void *)dev;

	return 0;
}

ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int i = -1, retval = -1;
	unsigned char val = 0xBB;

	read_lock(&dev->lock);
	val = dev->val;
	read_unlock(&dev->lock);

	for (i = 0; i < count; i++) {
		if (copy_to_user(&buf[i], &val, sizeof(unsigned char)) != 0) {
			retval = -EFAULT;
			goto out;
		}
	}
	retval = count;
out:
	return retval;
}

int devone_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int retval = -1;
	unsigned char val = 0x00;
	struct ioctl_cmd data;
	// 這裡很奇怪，在Kernel Spcae居然可以用memset()；但memset()是屬於<string.h>；但卻不能使用bzero()，
	// 因為初始化一個結構 (struct)應該使用bzero()，而memset()只能針對char的資料型態。
	memset(&data, 0, sizeof(struct ioctl_cmd));
//	bzero((void *)&data, sizeof(struct ioctl_cmd));
	switch (cmd) {
		case IOCTL_VALSET:
		/*	capable()是判斷User Process的執行權限。如CAP_SYS_ADMIN是判斷是否為"root"；
			至於還有哪些參考值可以用，請洽：/usr/src/kernels/2.6.33.3-85.fc13.i686.PAE/include/linux/capability.h
		*/	if (capable(CAP_SYS_ADMIN) == 0) {
				retval = -EPERM;
				goto done;
			}

			if (access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd)) == 0) {
				retval = -EFAULT;
				goto done;
			}

			if (copy_from_user(&data, (int __user *)arg, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto done;
			}

			printk(KERN_ALERT "IOCTL_cmd.val %u (%s). \n", data.val, __FUNC__);
			write_lock(&dev->lock);
			dev->val = data.val;
			write_unlock(&dev->lock);
			break;
		case IOCTL_VALGET:
		/*	至於access_ok()巨集則是判斷該指標所指到的記憶體空間是否可以讀寫；可以參考：
			/usr/src/kernels/2.6.33.3-85.fc13.i686.PAE/include/asm-generic/uaccess.h
		*/	if (!access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd))) {
				retval = -EFAULT;
				goto done;
			}

			read_lock(&dev->lock);
			val = dev->val;
			read_unlock(&dev->lock);
			data.val = val;
			
			if (copy_to_user((int __user *)arg, &data, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto done;
			}
			break;
		case IOCTL_VAL:
		case IOCTL_VALGETSET:
		// 以上這2個還不知道該怎麼用！
		default:
			retval = -ENOTTY;
			break;
	}
done:
	return retval;
}

int devone_close(struct inode *indoe, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;

	if (dev != (struct devone_data *)NULL)
		kfree((void *)dev);

	return 0;
}

struct file_operations devone_fops = {
	.owner = THIS_MODULE, 
	.open = devone_open,
	.release = devone_close, 
	.read = devone_read, 
	.ioctl = devone_ioctl, 
};

// "insnod"的Entry Point (進入點)！
static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);	
	int alloc_ret = 0, cdev_err = 0, major = 0;

	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME);
	if (alloc_ret != 0)
		goto error;
	devone_major = major = MAJOR(dev);
	devone_minor = MINOR(dev);

	cdev_init(&devone_cdev, &devone_fops);
	devone_cdev.owner = THIS_MODULE;
	devone_cdev.ops = &devone_fops;

	cdev_err = cdev_add(&devone_cdev, MKDEV(devone_major, devone_minor), 1);
	if (cdev_err != 0)
		goto error;

	devone_class = class_create(THIS_MODULE, "devone");
	if (IS_ERR(devone_class))
		goto error;

	printk(KERN_ALERT "%s driver (major: %d; minor: %d) install. \n", DRIVER_NAME, devone_major, devone_minor);

	return 0;
error:
	if (cdev_err == 0)
		cdev_del(&devone_cdev);

	if (alloc_ret == 0)
		unregister_chrdev_region(dev, devone_minor);

	return -1;
}

// "rmnod"的Entry Point (進入點)！
static void hello_exit(void)
{
	dev_t dev = MKDEV(devone_major, 0);

	class_destroy(devone_class);

	cdev_del(&devone_cdev);

	unregister_chrdev_region(dev, devone_devs);

	printk(KERN_ALERT "%s driver (major: %d; minor: %d) uninstall. \n", DRIVER_NAME, devone_major, devone_minor);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
