
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build120418
 *
 * Date: 2018 / 12 / 04
 *
 * Description: 
 * 1. 這一支範例程序的用意非常簡單，當驅動程式的模組devone只有一個，但設備卻有2個以上：/dev/devone0, devone1, devone2；使用者想要開啟不一樣的設備時，要做不一樣的事情，
 *     程式碼應該要怎麼寫！
 * 
 * 2. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

#define	DRIVER_NAME	"devone"

#define	__FUNC__		__func__

static int devone_devs = 3;		// Minor ID, 只允許支援3個設備，如devone0, devone1和devone2. 
static int devone_major = 0;
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;

// User Process open(), close(), read(), write(), /dev/devone2
static int two_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);

/*	inode->i_private = inode;
	file->private_data = file;
	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);
*/
	return 0;
}

static int two_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNC__, imajor(inode), iminor(inode), current->pid);

	return 0;
}

ssize_t two_read(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

ssize_t two_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

struct file_operations two_fops = {
	.open = two_open, 
	.release = two_close, 
	.read = two_read, 
	.write = two_write, 
};

// ====================================================================================
// User Process open(), close(), read(), write(), /dev/devone1. 
static int one_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);

/*	inode->i_private = inode;
	file->private_data = file;
	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);
*/
	return 0;
}

static int one_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNC__, imajor(inode), iminor(inode), current->pid);

	return 0;
}

ssize_t one_read(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

ssize_t one_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

struct file_operations one_fops = {
	.open = one_open, 
	.release = one_close, 
	.read = one_read, 
	.write = one_write, 
};

// ====================================================================================
// User Process open(), close(), read(), write(), /dev/devone0. 
static int zero_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);

/*	inode->i_private = inode;
	file->private_data = file;
	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);
*/
	return 0;
}

static int zero_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNC__, imajor(inode), iminor(inode), current->pid);

	return 0;
}

ssize_t zero_read(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

ssize_t zero_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_ALERT "%s called!! \n", __FUNC__);

	return 0;
}

struct file_operations zero_fops = {
	.open = zero_open, 
	.release = zero_close, 
	.read = zero_read, 
	.write = zero_write, 
};

// ====================================================================================
static int devone_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);

	switch (iminor(inode)) {
		case 0:
			file->f_op = &zero_fops;
			break;
		case 1:
			file->f_op = &one_fops;
			break;
		case 2:
			file->f_op = &two_fops;
			break;
		default:
			return -ENXIO;
	}

	if (file->f_op && file->f_op->open)
		return file->f_op->open(inode, file);

	return 0;
}

struct file_operations devone_fops = {
	.open = devone_open, 
};

// "mknod"的Entry Point (進入點)！
static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);
	int alloc_ret = 0, major = 0, minor = 0, cdev_err = 0;

	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME);
	if (alloc_ret != 0)
		goto error;
	devone_major = MAJOR(dev);
	major = devone_major;
	minor = MINOR(dev);

	cdev_init(&devone_cdev, &devone_fops);
	devone_cdev.owner = THIS_MODULE;

	cdev_err = cdev_add(&devone_cdev, MKDEV(devone_major, 0), devone_devs);
	if (cdev_err != 0)
		goto error;

	printk(KERN_ALERT "%s driver (major: %d; minor: %d) install. \n", DRIVER_NAME, major, minor);

	return 0;
error:
	if (cdev_err == 0)
		cdev_del(&devone_cdev);

	if (alloc_ret == 0)
		unregister_chrdev_region(dev, devone_devs);

	return -1;
}

// "rmnod"的Entry Point (進入點)！
static void hello_exit(void)
{
	dev_t dev = MKDEV(devone_major, 0);

	cdev_del(&devone_cdev);
	unregister_chrdev_region(dev, devone_devs);
	printk(KERN_ALERT "%s driver (major: %d; minor: %d) uninstall. \n", DRIVER_NAME, devone_major, MINOR(dev));

	return;
}

module_init(hello_init);
module_exit(hello_exit);
