
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122918
 *
 * Date: 2018 / 12 / 29
 *
 * Description: 
 * 1. 這一支程序展現了在Kernel Space中使用Semaphore (號誌)的用法，觀念上跟User Space的IPCs Semaphore一樣 (這裡並沒有搭配User Space的Process)。
 * 2. 程序中只有在讀寫 (R/W)的時候使用down_interruptible()來鎖定；讀寫完成之後再用up()來釋放。
 * 3. down()和down_interruptible()的差異在於後者可以被Single給中斷 (如Ctrl + C之類的)。
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("semaphore sample. ");
MODULE_VERSION("1.0.0.build122918");

#define	DRIVER_NAME	"devone"
#define	DATA_MAX	64

static int devone_devs = 1;
static int devone_major = 0;
static int devone_minor = 0;
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;
static struct class *devone_class = (struct class *)NULL;
static dev_t devone_dev;

struct devone_data {
	struct semaphore sem;
};

static unsigned char data[DATA_MAX];

// User Process "open()". 
static int devone_open(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)NULL;

	dev = (struct devone_data *)kmalloc(sizeof(struct devone_data), GFP_KERNEL);
	if (dev == (struct devone_data *)NULL)
		return -ENOMEM;

	init_MUTEX(&dev->sem);	// Initialize members
	filp->private_data = (struct file *)dev;

	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d; private_data = 0x%p \n", __FUNCTION__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid, filp->private_data);

	return 0;
}

// User Process "read()". 
static ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int len = -1, retval = -1;

	if (down_interruptible(&dev->sem) != 0)
		return -ERESTARTSYS;

	len = (count > DATA_MAX)? DATA_MAX: count;
	if (copy_to_user(buf, data, len) != 0) {
		retval = -EFAULT;
		goto out;
	}
	retval = len;
out:
	up(&dev->sem);

	return retval;
}

// User Process "write()". 
static ssize_t devone_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int len = -1, retval = -1;

	if (down_interruptible(&dev->sem) != 0)
		return -ERESTARTSYS;

	len = (count > DATA_MAX)? DATA_MAX: count;
	if (copy_from_user((void *)buf, data, len) != 0) {
		retval = -EFAULT;
		goto out;
	}
	retval = len;
out:
	up(&dev->sem);

	return retval;
}

// User Process "close()". 
static int devone_close(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;

	if (dev != (struct devone_data *)NULL)
		kfree((void *)dev);

	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNCTION__, imajor(inode), iminor(inode), current->pid);

	return 0;
}

struct file_operations devone_fops = {
	.owner = THIS_MODULE, 
	.open = devone_open, 
	.release = devone_close, 
	.read = devone_read, 
	.write = devone_write, 
};

// Modula Entry Point: insmod
static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);
	int alloc_ret = 0, major = 0, cdev_err = 0;
//	struct class_device *class_dev = (struct class_device *)NULL;

	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME);
	if (alloc_ret != 0)
		goto error;
	devone_major = MAJOR(dev);

	cdev_init(&devone_cdev, &devone_fops);
	devone_cdev.owner = THIS_MODULE;
	devone_cdev.ops = &devone_fops;

	cdev_err = cdev_add(&devone_cdev, MKDEV(devone_major, devone_minor), devone_devs);
	if (cdev_err != 0)
		goto error;
	// Register Class: class_create()函式會向系統登記一個class，然後在/sys/class/裡面建立指定的目錄如: /sys/class/devone/。
	devone_class = class_create(THIS_MODULE, "devone");
	if (IS_ERR(devone_class))
		goto error;
	
	devone_dev = MKDEV(devone_major, devone_minor);
	// class_device_create()是產生目錄之後 (/sys/class/devone/)，接著產生udev所需的裝置，如：/sys/class/devone/(devone). 
//	class_dev = class_device_create(devone_class, NULL, devone_dev, NULL, "devone%d", devone_minor);
	
	printk(KERN_ALERT "%s driver (major: %d; minor: %d) install. \n", DRIVER_NAME, major, MINOR(dev));

	return 0;
error:
	if (cdev_err == 0)
		cdev_del(&devone_cdev);

	if (alloc_ret == 0)
		unregister_chrdev_region(dev, devone_devs);

	return -1;
}

// Modula Entry Point: rmmod
static void hello_exit(void)
{
	dev_t dev = MKDEV(devone_major, 0);

//	class_device_destroy(devone_class, devone_dev);
	class_destroy(devone_class);
	cdev_del(&devone_cdev);
	unregister_chrdev_region(dev, devone_devs);
	printk(KERN_ALERT "%s driver (major: %d; minor: %d) uninstall. \n", DRIVER_NAME, devone_major, MINOR(dev));

	return;
}

module_init(hello_init);
module_exit(hello_exit);
