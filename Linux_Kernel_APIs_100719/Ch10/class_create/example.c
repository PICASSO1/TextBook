
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011119
 *
 * Date: 2019 / 01 / 11
 *
 * Description: 
 * 1. 這一支程式是延續cdev_alloc()一系列函式的範例修改而來。
 * 2. 會知道class_*()這一系列的函式，是因為在學習udev (Universal Device)的時候瞭解到有class_*()的函式。
 * 3. 原本的計畫是想要完成一個udev的裝置；不過目前看來似乎只有class_create()和class_destroy()可以正常運作。其餘的還並不是很清楚。
 * 4. class_create()是一個巨集 (Macro)的定義，定義如下：
 *     #define class_create(owner, name) \
 *     ({ \
 *         static struct lock_class_key __key; \
 *         __class_create(owner, name, &__key); \
 *     })
 * 5. void class_destroy(struct class *cls);
 * 6. class_create()和class_destroy()這兩個函式的功能非常簡單，就是在/sys/class/下建立和刪除相對應的資料夾而已。
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

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("class_create() and class_destroy() function sample. ");
MODULE_VERSION("1.0.0.build011119");

#define	DRIVER_NAME	"example"

static int example_major = 0;
static int example_base_minor = 0;
static int example_device_count = 1;
module_param(example_major, uint, 0);
dev_t dev = MKDEV(0, 0);
struct cdev *example_cdev = (struct cdev *)NULL;

static struct class *example_class = (struct class *)NULL;

struct file_operations example_fops = { };

static int hello_init(void)
{
	int region_err = 0, add_err = 0;

	region_err = alloc_chrdev_region(&dev, 6, example_device_count, DRIVER_NAME);
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

	example_class = class_create(THIS_MODULE, "example");
	if (IS_ERR(example_class))
		goto error;

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
	class_destroy(example_class);

	cdev_del(example_cdev);

	if (example_cdev != (struct cdev *)NULL)
		kfree((void *)example_cdev);

	unregister_chrdev_region(dev, example_device_count);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
