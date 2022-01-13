
/**
 * File Name: sleepon.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121418
 *
 * Date: 2018 / 12 / 14
 *
 * Description: 
 * 1. 這一支程序展現了sleep_op(); / wake_up(); 的用法；這兩個函式一定要成對出現。
 * 2. 在Kernel Space與User Space不同，在User Process可以用nice / renice指令或是函式來決定Process / Task執行時的優先順序，
 * 3. 可是在Kernel Space就算wake_up(); 寫在sleep_on(); 之後，但也並不保證它們執行時的先後順序。
 * 4. 所以使用sleep_op(); / wake_up(); 並不是一個好的方法；另外，使用這兩個函式時，要先用"wait_queue_head_t"來宣告變數及用init_waitqueue_head(); 函式來初始化。
 * 5. 這個範例的驗證方式：
 *     - make完之後，會產生sleepon.ko及wakeup.ko，並"insmod sleepon.ko"，且建立/dev/sleepon檔案；
 *     - 執行"hexdump -C -n 16 /dev/sleepon"指令，此時sleepon.ko模組就會進入睡眠 (sleep)狀態，
 *     - 再開一個Console Terminal視窗，執行"insmod wakeup.ko"，原本睡著的sleepon模組就會被叫起來。
 *
 * 6. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");

static int devone_devs = 1;
static int devone_major = 0;
static int devone_minor = 0;
//module_param(devone_major, uint, 0);
struct cdev devone_cdev;

wait_queue_head_t picasso_sample_wait;

EXPORT_SYMBOL(picasso_sample_wait);

ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	int i = -1, retval = -1;
	unsigned char val = 0xBB;

	init_waitqueue_head(&picasso_sample_wait);
	sleep_on(&picasso_sample_wait);
	printk(KERN_ALERT "Wake Up (%s)!! \n", __FUNCTION__);

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
	.owner = THIS_MODULE, 
	.read = devone_read, 
};

// "insnod"的Entry Point (進入點)！
static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);	
	int alloc_ret = 0, cdev_err = 0, major = 0;

	alloc_ret = alloc_chrdev_region(&dev, 0, devone_devs, DRIVER_NAME0);
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

	printk(KERN_ALERT "%s driver (major: %d; minor: %d) install. \n", DRIVER_NAME0, devone_major, devone_minor);

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

	cdev_del(&devone_cdev);

	unregister_chrdev_region(dev, devone_devs);

	printk(KERN_ALERT "%s driver (major: %d; minor: %d) uninstall. \n", DRIVER_NAME0, devone_major, devone_minor);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
