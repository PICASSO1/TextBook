
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011019
 *
 * Date: 2019 / 01 / 10
 *
 * Description: 
 * 1. 相對於Static Register (靜態註冊)的register_chrdev()和unregister_chrdev()函式；這一個範例則是使用Dynamic Register (動態註冊)的alloc_chr
 *     dev_region()和unregister_chrdev_region()函式。2個函式的原型如下：
 *
 * 2. int alloc_chrdev_region(dev_t *dev, unsigned int baseminor, unsigned int count, const char *name);
 *     第1個參數dev_t *dev: 核心系統動態取得的Major ID，會以Call by Reference的方式回傳至這一個參數，用MAJOR(dev)即可取得。
 *     第2個參數unsigned int baseminor: 所有設備Minor ID的起始值，大部分的情況之下都是填0。
 *     第3個參數unsigned int count: 是這乙支驅動程式 (Driver)要「支援幾個設備」。
 *     第4個參數const char *name: 則是驅動程式的名稱。
 *     
 *     例如：在第2個參數 (unsigned int baseminor)填0的時候，每一個設備的Major ID和Minor ID對應如下：
 *     /dev/example0 (major: 250; minor: 0)
 *     /dev/example1 (major: 250; minor: 1)
 *     /dev/example2 (major: 250; minor: 2)
 *     若是改填4的時候就會變成：
 *     /dev/example0 (major: 250; minor: 4)
 *     /dev/example1 (major: 250; minor: 5)
 *     /dev/example2 (major: 250; minor: 6)
 *     所以，當使用MINOR(dev)的時候，取得的是「Minor ID的起始值」而非「支援設備的數量」！
 *
 * 3. void 和unregister_chrdev_region(dev_t from, unsigned int count);
 *
 * 4. 初始化dev_t的資料型態，可用MKDEV(ma, mi)巨集即可，ma和mi都填0也無所謂，因為在使用alloc_chrdev_region()函式時，會以Call by Reference
 *     的方式回傳。 同理；MKDEV()的第2個參數mi也是指「Minor ID的起始值」。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("alloc_chrdev_region() and unregister_chrdev_region() sample. ");
MODULE_VERSION("1.0.0.build011019");

#define	DRIVER_NAME	"example"

static int example_major = 0;
static int example_base_minor = 0;
static int example_device_count = 3;
module_param(example_major, uint, 0);
dev_t dev = MKDEV(0, 0);

static int hello_init(void)
{
	int ret = 0;

	ret = alloc_chrdev_region(&dev, 6, example_device_count, DRIVER_NAME);
	if (ret < 0) {
		printk(KERN_ERR "%s (alloc_chrdev_region() and unregister_chrdev_region()) driver registration error!! \n", DRIVER_NAME);
		goto error;
	}
	example_major = MAJOR(dev);
	example_base_minor = MINOR(dev);

	printk(KERN_INFO "%s (alloc_chrdev_region() and unregister_chrdev_region()) driver installed (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	return 0;
error:	
	if (ret < 0)
		unregister_chrdev_region(dev, example_device_count);

	return -1;
}

static void hello_exit(void)
{
	unregister_chrdev_region(dev, example_device_count);
	printk(KERN_INFO "%s (alloc_chrdev_region() and unregister_chrdev_region()) driver uninstalled (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
