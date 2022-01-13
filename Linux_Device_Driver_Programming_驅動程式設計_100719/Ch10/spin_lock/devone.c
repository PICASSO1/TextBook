
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build123018
 *
 * Date: 2018 / 12 / 30
 *
 * Description: 
 * 1. 這一個SpinLock (自旋鎖，Busy-Loop)的範例，是按照課本上打的；可是一直有Error。可以make過，但在User Space的程式一執行open()整個程式就當掉了。
 * 2. 加了一些Debug Messages之後，發現在devone_open()函式中執行到"add_timer(&dev->tickfn); "這一行就掛掉了....目前還不清楚原因！
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("SpinLock (自旋鎖，Busy-Loop) sample. ");
MODULE_VERSION("1.0.0.build122918");

#define	DRIVER_NAME		"devone"
#define	DATA_MAX		64
#define	TIMEOUT_VALUE	(5 * HZ)

static int devone_devs = 1;
static int devone_major = 0;
static int devone_minor = 0;
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;
static struct class *devone_class = (struct class *)NULL;
static dev_t devone_dev;

struct devone_data {
	spinlock_t lock;
	struct timer_list tickfn;
};

static unsigned char sample_data[DATA_MAX];

static void devone_timeout(unsigned long arg)
{
	struct devone_data *dev = (struct devone_data *)arg;
	int i = -1;
	unsigned long flags = 0UL;

	printk(KERN_ALERT "%s entered.... \n", __FUNCTION__);
//	spin_lock(&dev->lock);
	spin_lock_irqsave(&dev->lock, flags);
	for (i = 0; i < DATA_MAX; i++)
		sample_data[i]++;
//	spin_unlock(&dev->lock);
	spin_unlock_irqrestore(&dev->lock, flags);
	mod_timer(&dev->tickfn, jiffies + TIMEOUT_VALUE);

	return;
}

static int devone_open(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)NULL;

	dev = (struct devone_data *)kmalloc(sizeof(struct devone_data), GFP_KERNEL);
	if (dev == (struct devone_data *)NULL)
		return -ENOMEM;

	spin_lock_init(&dev->lock);
	dev->tickfn.function = devone_timeout;
	dev->tickfn.data = (unsigned long)dev;
	dev->tickfn.expires = jiffies + TIMEOUT_VALUE;
	add_timer(&dev->tickfn);		// 執行到這一行就當掉了？

	filp->private_data = (struct file *)dev;
/*	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d; private_data = 0x%p \n", __FUNCTION__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid, filp->private_data);
*/
	return 0;
}

static ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int len = -1, retval = -1, i = -1;
	unsigned long flags = 0UL;
	unsigned char tmpbuf[DATA_MAX];
	// Copying the global data to the temporary buffer while holding a spinlock. 
	spin_lock_irqsave(&dev->lock, flags);
//	spin_lock(&dev->lock);
	for (i = 0; i < DATA_MAX; i++)
		tmpbuf[i] = sample_data[i];
	mdelay(3000);
	spin_unlock_irqrestore(&dev->lock, flags);
//	spin_unlock(&dev->lock);
	len = (count > DATA_MAX)? DATA_MAX: count;
	if (copy_to_user((void *)buf, tmpbuf, len)) {
		retval = -EFAULT;
		goto out;
	}
	retval = len;
out:
	return retval;
}

static ssize_t devone_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

static int devone_close(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;

	if (dev != (struct devone_data *)NULL) {
		del_timer_sync(&dev->tickfn);
		kfree((void *)dev);
	}
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

static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);
	int alloc_ret = 0, major = 0, cdev_err = 0;
//	struct class_device *class_dev = (struct class_device *)NULL;

	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME);
	if (alloc_ret != 0)
		goto error;
	devone_major = major = MAJOR(dev);

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
