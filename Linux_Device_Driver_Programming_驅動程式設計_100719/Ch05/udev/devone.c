
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
 * 1. 這一個Linux Kernel的範例程序，主要是在講Linux的"udev" (Universal Device)機制。
 * 2. 驅動程式最初的作法是：編譯出*.ko檔之後，insmod *.ko；然後再mknod /dev/(device)。
 * 3. 這一種作法有一個問題，那就是如果Hardware根本就不在呢？縱使有Module (模組)和設備檔依舊無法運作。
 * 4. 進而產生了可以HotPlug (熱插拔)的udev機制––當硬體備妥之後，藉由udev偵測到新的硬體，才insmod (module)和mknod /dev/(device)；
 * 5. 且移除裝置時也能夠自動rmmod (module)和rm -vf /dev/(device)。所以udev的運作流程就非常重要
 *     a). 開機程序的Script (/etc/rc.d/rc.sysinit)會呼叫/sbin/start_udev來建立裝置檔 (/dev/*)；
 *     b). 至於要建立哪些裝置檔，可以在/etc/udev/makedev.d/的目錄中找到。
 *     c). 為驅動程式已經有支援udev機制，所以當然也包含Major / Minor ID；當udevd偵測到之後，會先去檢查/sys/class/目錄；
 *     d). 就會依據驅動程式所給的資訊來建立裝置檔 (/dev/*)；
 *     e). 至於裝置檔的"規則" (權限，檔名，擁有者)，則是寫在/etc/udev/rules.d/的目錄之內。
 * 6. class_device_create() / class_device_destroy()這兩個函式是linux-2.4.x在用的；現在linux-2.6.x已無支援。取而代之的好像是class_register()
 *     和class_unregister()。有空再研究一下Kernel API書上的範例。
 * 2019 / 01 / 14: 
 * 7. 承6. ，class_device_create()和class_device_destroy()是linux-2.6.x較舊的版本在用的；較新的版本則是改使用device_create()和
 *     device_destroy()這兩支函式。一樣可以達到udev的相關功能。
 * 8. 要注意：device_create()和device_destroy()會自動建立和刪除/dev/*下的檔案，所以在Makefile中不必再執行：
 *     /bin/mknod /dev/(Device Name) b/c (Major ID) (Minor ID)和/bin/rm /dev/(Device Name) 指令。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/device.h>	// 引入這個標頭檔，可以使用udev相關函式！
#include <asm/current.h>	// 引入這個標頭檔，可以用current->pid取得User Process的PID!!
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

#define	DRIVER_NAME	"devone"

static int devone_devs = 1;		// Minor ID, 只允許支援1個設備，如devone
static int devone_major = 0;		// Major: dynamic allocation
static int devone_minor = 0;		// Minor: static allocation
module_param(devone_major, uint, 0);
static struct cdev devone_cdev;
static struct class *devone_class = (struct class *)NULL;
static dev_t devone_dev;

// User Process "open()". 
static int devone_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d \n", __FUNCTION__, \
		MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid);

	inode->i_private = inode;
	file->private_data = file;

	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);

	return 0;
}

// User Process "close()". 
static int devone_close(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "%s: imajor(inode): %d; iminor(inode): %d; PID: %d \n", __FUNCTION__, imajor(inode), iminor(inode), current->pid);

	printk(KERN_ALERT "i_private = %p private_data = %p \n", inode->i_private, file->private_data);

	return 0;
}

// User Process "read()". 
static ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	int i = -1, retval = -1;
	unsigned char val = 0xCC;

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

struct file_operations devone_fops = {
	.open = devone_open, 
	.release = devone_close, 
	.read = devone_read,
};

// "insnod"的Entry Point (進入點)！
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
	// 用device_create()取代class_device_create()！
	device_create(devone_class, NULL, MKDEV(devone_major, devone_minor), NULL, "devone");
	
	printk(KERN_ALERT "%s driver (major: %d; minor: %d) install. \n", DRIVER_NAME, major, MINOR(dev));

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
	// 用device_destroy()取代class_device_destroy()！
	device_destroy(devone_class, MKDEV(devone_major, devone_minor));
//	class_device_destroy(devone_class, devone_dev);	// 刪除目錄裡的裝置: /sys/class/devone/devone
	class_destroy(devone_class);					// 註銷class且刪除/sys/class/devone/目錄。
	cdev_del(&devone_cdev);
	unregister_chrdev_region(dev, devone_devs);
	printk(KERN_ALERT "%s driver (major: %d; minor: %d) uninstall. \n", DRIVER_NAME, devone_major, MINOR(dev));

	return;
}

module_init(hello_init);
module_exit(hello_exit);
