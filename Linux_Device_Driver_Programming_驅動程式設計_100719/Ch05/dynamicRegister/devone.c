
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build112918
 *
 * Date: 2018 / 11 / 29
 *
 * Description: 
 * 1. 這一支程序是展現cdev_init(), cdev_add()和cdev_del()函式的用法。PS: cdev_*: character device (字元設備)....
 * 2. 但是這一支Kernel Space的程式是使用alloc_chrdev_region()和unregister_chrdev_region()。是屬於Dynamic Register (動態註冊)；linux-2.6.x之後均採用此一方法。
 * 3. Major ID是Linux Kernel要管理Driver (驅動程式)用的；而Minor ID是Driver (驅動程式)要管理幾個設備用的，如Driver "devone"，可以有devone0, devone1, devone2等3個設備。
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

MODULE_LICENSE("Dual BSD/GPL");

#define	DRIVER_NAME	"devone"

#define	__FUNC__		__func__

static int devone_devs = 3;		// Minor ID, 只允許支援3個設備，如devone0, devone1和devone2. 
static int devone_major = 0;
/*
使用module_param()巨集的用意是：當使用"insmod (Module Name) b/c (Major ID) (Minor ID)"指令時，可以動態指定Major ID，如"inmod *.ko"，
或是"insmode *.ko devone_major=261". 
*/
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;

// User Process "open()". 
static int devone_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNC__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);
	// 使用MAJOR()和MINOR()巨集可以透過inode的i_rdev成員分別取得Major / Minor ID；但若是struct indoe成員結構改變，恐怕無法使用！
	inode->i_private = inode;
	file->private_data = file;

	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);

	return 0;
}

// User Process "close()". 
static int devone_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNC__, imajor(inode), iminor(inode), current->pid);
	// 為了解決MAJOR() / MINOR()巨集可攜行的問題，建議改用imajor() / iminor()函式。
	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);

	return 0;
}

struct file_operations devone_fops = {
	.open = devone_open, 
	.release = devone_close, 
};

// "mknod"的Entry Point (進入點)！
static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);
	int alloc_ret = 0, major = 0, minor = 0, cdev_err = 0;

	// alloc_chrdev_region(): 向kernel動態註冊Major ID。成功回傳0；失敗為複數。
	// 第1個參數：要儲存的設備；第2個參數：Minor ID的"起始點"，通常都是填0；
	// 第3個參數：要支援多少個設備，就是指Minor ID；第4個參數：驅動程式的名稱。
	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME);
	if (alloc_ret != 0)
		goto error;
	devone_major = MAJOR(dev);
	major = devone_major;
	minor = MINOR(dev);

	cdev_init(&devone_cdev, &devone_fops);	// cdev_init(): character device initial; 初始化我們要新增的字元設備
	devone_cdev.owner = THIS_MODULE;		// Needed this line ....
	// cdev_add(): character add: 向kernel新增一個字元設備
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
