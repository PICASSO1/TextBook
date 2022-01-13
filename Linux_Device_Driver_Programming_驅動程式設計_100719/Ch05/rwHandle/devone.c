
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build120118
 *
 * Date: 2018 / 12 / 01
 *
 * Description: 
 * 1. 這一支程序是從"dynamicRegister"繼承而來修改；
 * 2. 原本只有open()和close()這兩個User Space的Handler，這一次新增了read()和write()；當然也要搭配User Space程序的修改。
 * 3. 除此之外還新增了一些Kernel Space的API: rwlock_t lock, rwlock_init(), read_lock(), read_unlock(), write_lock(), write_unlock(), copy_to_user(), copy_from_user(), 
 *     kmalloc()和kfree()等等，因為太多了有空再研究！
 * 
 * 4. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/current.h>	// 引入這個標頭檔，可以用current->pid取得User Process的PID!!
#include <asm/uaccess.h>
#include <linux/slab.h>		// for kmalloc() and kfree()

MODULE_LICENSE("Dual BSD/GPL");

#define	DRIVER_NAME	"devone"

#define	__FUNC__		__func__

static int devone_devs = 1;		// Minor ID, 只允許支援1個設備，如：devone
static int devone_major = 0;
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;

struct devone_data {
	unsigned char val;
	rwlock_t lock;
};

// User Process "open()". 
static int devone_open(struct inode *inode, struct file *file)
{
	struct devone_data *p = (struct devone_data *)NULL;

	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);
	// 使用MAJOR()和MINOR()巨集可以透過inode的i_rdev成員分別取得Major / Minor ID；但若是struct indoe成員結構改變，恐怕無法使用！
	p = kmalloc(sizeof(struct devone_data), GFP_KERNEL); 
	if (p == (struct devone_data *)NULL) {
		printk(KERN_ALERT "%s: Not memory. \n", __FUNC__);
		return -ENOMEM;
	}

	p->val = 0xFF;
	rwlock_init(&p->lock);
	file->private_data = p;

	return 0;
}

// User Process "read()". 
ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *p = (struct devone_data *)filp->private_data;
	int i = -1, retval = -1;
	unsigned char val = 0xBB;

	read_lock(&p->lock);
	val = p->val;
	read_unlock(&p->lock);

	printk(KERN_ALERT "%s: count: %d; f_pos: %lld \n", __FUNC__, count, *f_pos);
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

// User Process "write()". 
ssize_t devone_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *p = (struct devone_data *)filp->private_data;
	int retval = -1;
	unsigned char val = 0xAA;

	printk(KERN_ALERT "%s: count: %d; f_pos: %lld \n", __FUNC__, count, *f_pos);
	if (count >= 1) {
		if (copy_from_user(&val, &buf[0], sizeof(unsigned char)) != 0) {
			retval = -EFAULT;
			goto out;
		}
	//	printk(KERN_ALERT "%02X ", val);
		write_lock(&p->lock);
		p->val = val;
		write_unlock(&p->lock);
		retval = count;
	}

out:
	return retval;
}

// User Process "close()". 
static int devone_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNC__, imajor(inode), iminor(inode), current->pid);
	// 為了解決MAJOR() / MINOR()巨集可攜行的問題，建議改用imajor() / iminor()函式。
	if (file->private_data) {
		kfree((void *)file->private_data);
		file->private_data = NULL;
	}

	return 0;
}

struct file_operations devone_fops = {
	.open = devone_open, 
	.read = devone_read, 
	.write = devone_write, 
	.release = devone_close, 
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
