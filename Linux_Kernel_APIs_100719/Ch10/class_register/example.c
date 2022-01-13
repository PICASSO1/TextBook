
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011419
 *
 * Date: 2019 / 01 / 14
 *
 * Description: 
 * 1. 這一支程式是延續class_create()一系列函式的範例修改而來。
 * 2. 「class_register()和class_unregister()」這2支函式的功能，完全等同於「class_create()和class_destroy()」。
 * 3. 這4支函式的功能就是在/sys/class/下建立和刪除相對應的資料夾而已。
 * 4. 若要完成udev功能的相關檔案，則要再加上device_create()和device_destroy()函式。函式原型如下：
 * 5. class_register()是一個巨集 (Macro)的定義，定義如下：
 *     #define class_register(class) \
 *     ({ \
 *         static struct lock_class_key __key; \
 *         __class_register(class, &__key); \
 *     })
 * 6. void class_unregister(struct class *class);
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
MODULE_DESCRIPTION("class_register() and class_unregister() function sample. ");
MODULE_VERSION("1.0.0.build011419");

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
	int region_err = 0, add_err = 0, cls_err = 0;

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

	example_class = (struct class *)kzalloc(sizeof(struct class), GFP_KERNEL);
	if (IS_ERR(example_class))
		goto error;

	example_class->name = "example";
	example_class->owner = THIS_MODULE;
//	example_class->class_release = ;
	cls_err = class_register(example_class);
	if (cls_err != 0) {
		printk(KERN_ERR "%s driver class_register() failed (cls_err = %d)!! \n", DRIVER_NAME, cls_err);
		goto error;
	}
	printk(KERN_INFO "%s driver class_register() successfully!! \n", DRIVER_NAME);

	device_create(example_class, NULL, MKDEV(example_major, example_base_minor), NULL, "example");
	printk(KERN_INFO "%s driver device_create() successfully!! \n", DRIVER_NAME);
	
	return 0;
error:
	if ((example_class != (struct class *)NULL) || (cls_err != 0))
		kfree((void *)example_class);

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
	device_destroy(example_class, MKDEV(example_major, example_base_minor));
	printk(KERN_INFO "%s driver device_destroy() successfully!! \n", DRIVER_NAME);

	class_unregister(example_class);
	printk(KERN_INFO "%s driver class_unregister() successfully!! \n", DRIVER_NAME);

	cdev_del(example_cdev);

	if (example_cdev != (struct cdev *)NULL)
		kfree((void *)example_cdev);

	unregister_chrdev_region(dev, example_device_count);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
