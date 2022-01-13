
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build120918
 *
 * Date: 2018 / 12 / 09
 *
 * Description: 
 * 1. 這一支Kernal Space的程序，展現了select()的用法；但User Process的select()用法有點抽象，可以參考Socket Programming Select的部份比較容易理解該怎麼用。
 * 2. 但是，這一個課本上的範例實在是有點難，用了很多後面的課程才會提到的觀念。等後面的學到了之後再回過頭來看。
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

#include <linux/sched.h>
#include <asm/current.h>

MODULE_LICENSE("Dual BSD/GPL");

static unsigned int timeout_value = 10;
module_param(timeout_value, uint, 0);

static int devone_devs = 1;
static int devone_major = 0;
static int devone_minor = 0;
static struct cdev devone_cdev;
static struct class *devone_class = (struct class *)NULL;

struct devone_data {
	struct timer_list timeout;
	spinlock_t lock;
	wait_queue_head_t read_wait;
	int timeout_done;
	struct semaphore sem;
};

static void devone_timeout(unsigned long arg)
{
	struct devone_data *dev = (struct devone_data *)arg;
	unsigned long flags = 0U;

	printk(KERN_ALERT "%s called. \n", __FUNC__);

	spin_lock_irqsave(&dev->lock, flags);
	dev->timeout_done = 1;
	wake_up_interruptible(&dev->read_wait);
	spin_unlock_irqrestore(&dev->lock, flags);

	return;
}

int devone_open(struct inode *indoe, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)NULL;

	dev = (struct devone_data *)kmalloc(sizeof(struct devone_data), GFP_KERNEL);
	if (dev == (struct devone_data *)NULL)
		return -ENOMEM;

	// initialize members
	spin_lock_init(&dev->lock);
	init_waitqueue_head(&dev->read_wait);
	init_MUTEX(&dev->sem);
	init_timer(&dev->timeout);

	dev->timeout.function = devone_timeout;
	dev->timeout.data = (unsigned long)dev;

	filp->private_data = dev;
	// Start Timer
	dev->timeout_done = 0;
	mod_timer(&dev->timeout, jiffies + timeout_value * HZ);

	return 0;
}

ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int i = -1, retval = -1;
	unsigned char val = 0x00;

	if (down_interruptible(&dev->sem))
		return -ERESTARTSYS;

	if (dev->timeout_done == 0) {		// no read
		up(&dev->sem);
		if (filp->f_flags & O_NONBLOCK)	// Non-Blocking Mode
			return -EAGAIN;

		do {
			retval = wait_event_interruptible_timeout(dev->read_wait, dev->timeout_done == 1, 1 * HZ);
			if (retval == -ERESTARTSYS)
				return -ERESTARTSYS;
		} while (retval == 0);			// timeout elapsed
		
		if (down_interruptible(&dev->sem))
			return -ERESTARTSYS;
	}

	val = 0xFF;
	for (i = 0; i < count; i++) {
		if (copy_to_user(&buf[i], &val, 1)) {
			retval = -EFAULT;
			goto out;
		}
	}

	retval = count;
out:
	dev->timeout_done = 0;
	// restart timer
	mod_timer(&dev->timeout, jiffies + timeout_value * HZ);
	up(&dev->sem);
	
	return retval;
}

ssize_t devone_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT;
}

unsigned int devone_poll(struct file *filp, poll_table *wait)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	unsigned int mask = POLLOUT | POLLWRNORM;

	printk(KERN_ALERT "%s called. \n", __FUNC__);
	if (dev == (struct devone_data *)NULL)
		return -EBADFD;

	down(&dev->sem);
	poll_wait(filp, &dev->read_wait, wait);
	if (dev->timeout_done == 1)
		mask |= POLLIN | POLLRDNORM;

	up(&dev->sem);
	printk(KERN_ALERT "%s returned (mask 0x%X). \n", __FUNC__, mask);

	return mask;
}

int devone_close(struct inode *indoe, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;

	if (dev != (struct devone_data *)NULL) {
		del_timer_sync(&dev->timeout);
		kfree((void *)dev);
	}

	return 0;
}

struct file_operations devone_fops = {
	.owner = THIS_MODULE, 
	.open = devone_open,
	.release = devone_close, 
	.read = devone_read, 
	.write = devone_write, 
	.poll = devone_poll, 
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
