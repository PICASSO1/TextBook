
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011719
 *
 * Date: 2019 / 01 / 17
 *
 * Description: 
 * 1. 這一個範例是介紹如何在模組中取得當下的「參考計數 (Reference Count)」，使用module_refcount()函式：
 *     unsigned int module_refcount(struct module *mod); 回傳值就是當時的參考計數。
 * 
 * 2. 關於Kernel Spcae中的「參考計數 (Reference Count)」和「連結計數 (Link Count)」的規則如下：
 *     a). 刪除檔案 (delete)會使「連結計數 (Link Count)」減1；
 *     b). 打開檔案 (open)會使「參考計數 (Reference Count)」加1；
 *     c). 關閉檔案 (close)會使「參考計數 (Reference Count)」減1；
 *     d). 當「參考計數 (Reference Count)」"等於1"，且「連結計數 (Link Count)」也"等於1"時，才能夠刪除檔案。
 * 
 * 3. 從執行結果看來，參考計數 (Reference Count)的運作，系統似乎都幫我們做好了....
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>
#include <linux/ioctl.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("module_refcount() function sample. ");
MODULE_VERSION("1.0.0.build011719");

#define	DRIVER_NAME	"example"

static int example_major = 0;
static int example_base_minor = 0;
static int example_device_count = 2;
module_param(example_major, uint, 0);
dev_t dev = MKDEV(0, 0);
struct cdev *example_cdev = (struct cdev *)NULL;

static int eight_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; Reference Count: %d \n", \
		__FUNCTION__, imajor(inode), iminor(inode), module_refcount(THIS_MODULE));

	return 0;
}

static int eight_close(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; Reference Count: %d \n", \
		__FUNCTION__, imajor(inode), iminor(inode), module_refcount(THIS_MODULE));

	return 0;
}

struct file_operations eight_fops = {
	.open = eight_open, 
	.release = eight_close, 
};

static int nine_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; Reference Count: %d \n", \
		__FUNCTION__, imajor(inode), iminor(inode), module_refcount(THIS_MODULE));

	return 0;
}

static int nine_close(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; Reference Count: %d \n", \
		__FUNCTION__, imajor(inode), iminor(inode), module_refcount(THIS_MODULE));

	return 0;
}

struct file_operations nine_fops = {
	.open = nine_open, 
	.release = nine_close, 
};

static int example_open(struct inode *inode, struct file *file)
{
	switch (iminor(inode)) {
		case 8:
			file->f_op = &eight_fops;
			break;
		case 9:
			file->f_op = &nine_fops;
			break;
		default:
			return -ENXIO;
	}

	if (file->f_op && file->f_op->open)
		return file->f_op->open(inode, file);

	return 0;
}

struct file_operations example_fops = {
	.open = example_open, 
};

static int hello_init(void)
{
	int region_err = 0, add_err = 0;

	region_err = alloc_chrdev_region(&dev, 8, example_device_count, DRIVER_NAME);
	if (region_err < 0)
		goto error;
	example_major = MAJOR(dev);
	example_base_minor = MINOR(dev);

	example_cdev = cdev_alloc();
	if (example_cdev == (struct cdev *)NULL)
		goto error;

	cdev_init(example_cdev, &example_fops);	
	example_cdev->owner = THIS_MODULE;
	add_err = cdev_add(example_cdev, MKDEV(example_major, example_base_minor), example_device_count);
	if (add_err != 0)
		goto error;

	printk(KERN_INFO "%s driver installed (Major ID: %d; Base Minor ID: %d; Device Count: %d; Reference Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count, module_refcount(THIS_MODULE));

	return 0;
error:
	if (add_err != 0)
		cdev_del(example_cdev);

	if (example_cdev == (struct cdev *)NULL)
		kfree((void *)example_cdev);

	if (region_err < 0)
		unregister_chrdev_region(dev, example_device_count);

	return -1;
}

static void hello_exit(void)
{
	cdev_del(example_cdev);

	if (example_cdev != (struct cdev *)NULL)
		kfree((void *)example_cdev);

	unregister_chrdev_region(dev, example_device_count);

	printk(KERN_INFO "%s driver uninstalled (Major ID: %d; Base Minor ID: %d; Device Count: %d; Reference Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count, module_refcount(THIS_MODULE));

	return;
}

module_init(hello_init);
module_exit(hello_exit);
