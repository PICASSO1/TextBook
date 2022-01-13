
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build112518
 *
 * Date: 2018 / 11 / 25
 *
 * Description: 
 * 1. 這一支程序是展現register_chrdev()和unregister_chrdev()這兩支函式的用法；若是要最原始的Pure Static Register (純靜態註冊)，可以參考自己另外寫的範例：Linux_Kernel_A
 *     PI/Ch10/register_unregister_chrdev/
 * 2. 但是這一支Kernel Space的程式雖然使用register_chrdev()和unregister_chrdev()；卻採用Dynamic Register (動態註冊)。
 * 3. 若register_chrdev()第一個傳進去的參數為0，回傳值就會是一個動態的Major ID。
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

static unsigned int devone_major = 0;
/*
使用module_param()巨集的用意是：當使用"insmod (Module Name) b/c (Major ID) (Minor ID)"指令時，可以動態指定Major ID，如"inmod *.ko"，
或是"insmode *.ko devone_major=261". 
*/
module_param(devone_major, uint, 0);

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
	int major = 0, ret = 0;
	// 若要使用(un)register_chrdev()函式來動態取得Major ID，就用下面這一種寫法，傳進去的第1個參數為0，回傳值為Major ID。
	major = register_chrdev(devone_major, DRIVER_NAME, &devone_fops);
	if ((devone_major > 0 && major != 0) || \
		(devone_major == 0 && major < 0) || \
		major < 0) {
		printk(KERN_ALERT "%s driver registration error!! \n", DRIVER_NAME);
		ret = major;

		goto error;
	}

	if (devone_major == 0)
		devone_major = major;

	printk(KERN_ALERT "%s driver (major: %d) install. \n", DRIVER_NAME, devone_major);

error:
	return ret;
}

// "rmnod"的Entry Point (進入點)！
static void hello_exit(void)
{
	unregister_chrdev(devone_major, DRIVER_NAME);

	printk(KERN_ALERT "%s driver (major: %d) uninstall. \n", DRIVER_NAME, devone_major);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
