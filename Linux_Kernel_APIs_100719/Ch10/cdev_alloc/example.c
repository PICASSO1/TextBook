
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
 * 1. 這一支程式是延續alloc_chrdev_region()和unregister_chrdev_region()的範例修改而來。
 * 2. Static Register (靜態註冊)的register_chrdev()和unregister_chrdev()函式，以及Dynamic Register (動態註冊)的alloc_chrdev_region()和unreg
 *     ister_chrdev_region()函式；這4支函式的功能只是向核心系統去註冊一個Character Device (字元設備)的Major ID, Base Minor ID, 設備數量以及驅
 *     動程式的模組名稱。
 * 3. 而這一個範例的cdev_*()系列函式則是真正地向核心系統去增加一個Character Device (cdev, 字元設備)。函式原型如下：
 * 4. struct cdev *cdev_alloc(void);
 * 5. void cdev_init(struct cdev *, const struct file_operation *);
 * 6. int cdev_add(struct cdev *, dev_t, unsigned int);
 * 7. void cdev_del(struct cdev *);
 *     因為參數還算蠻簡單的，就不再贅述，看範例程式即可！
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("cdev_*() function sample. ");
MODULE_VERSION("1.0.0.build011019");

#define	DRIVER_NAME	"example"

static int example_major = 0;
static int example_base_minor = 0;
static int example_device_count = 1;
module_param(example_major, uint, 0);
dev_t dev = MKDEV(0, 0);
struct cdev *example_cdev = (struct cdev *)NULL;

struct file_operations example_fops = { };

static int hello_init(void)
{
	int region_err = 0, add_err = 0;

	region_err = alloc_chrdev_region(&dev, 6, example_device_count, DRIVER_NAME);
	if (region_err < 0) {
		printk(KERN_ERR "%s (cdev_*()) driver registration error!! \n", DRIVER_NAME);
		goto error;
	}
	example_major = MAJOR(dev);
	example_base_minor = MINOR(dev);

	printk(KERN_INFO "%s (cdev_*()) driver installed (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	example_cdev = cdev_alloc();
	if (example_cdev == (struct cdev *)NULL) {
		printk(KERN_ERR "%s (cdev_*()) driver cdev_alloc() failed!! \n", DRIVER_NAME);
		goto error;
	}
	printk(KERN_INFO "%s (cdev_*()) driver cdev_alloc() successfully!! Address (example_cdev): 0x%08X. \n", \
		DRIVER_NAME, (unsigned int)example_cdev);

	if (example_cdev->ops == (struct file_operations *)NULL)	// for testing!!
		printk(KERN_NOTICE "0. The ops of the cdev_init() hasn't been initialized. \n");
	else
		printk(KERN_NOTICE "0. The ops of the cdev_init() has been initialized. \n");
	
	cdev_init(example_cdev, &example_fops);
	
	if (example_cdev->ops == (struct file_operations *)NULL)	// for testing!!
		printk(KERN_NOTICE "1. The ops of the cdev_init() hasn't been initialized. \n");
	else
		printk(KERN_NOTICE "1. The ops of the cdev_init() has been initialized. \n");
	/** 2019 / 01 / 10, by Picasso
	* 當還沒有執行cdev_init()時，因為cdev_alloc()函式才配置記憶體空間，照理說struct cdev下的成員應都為空值；
	* 執行cdev_init()之後，因為第2個參數已經傳進去struct file_operations的記憶體位址，所以ops成員就不會為NULL值。
	(*)?*/
	example_cdev->owner = THIS_MODULE;
	add_err = cdev_add(example_cdev, MKDEV(example_major, example_base_minor), example_device_count);
	if (add_err != 0) {
		printk(KERN_ERR "%s (cdev_*()) driver cdev_add() failed!! \n", DRIVER_NAME);
		goto error;
	}

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

	printk(KERN_INFO "%s (cdev_*()) driver uninstalled (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
