
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011819
 *
 * Date: 2019 / 01 / 18
 *
 * Description: 
 * 1. 這一支程序是用來展現如何在模組當中「增加參考計數 (Reference Count)」和「減少參考計數 (Reference Count)」。
 * 2. linux-2.6.x以後用try_module_get()函式來"增加"參考計數，取代原本linux-2.4.x的"MOD_INC_USE_COUNT; "巨集；
 *     用module_put()函式來"減少"參考計數，取代原本linux-2.4.x的"MOD_DEC_USE_COUNT; "巨集。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("try_module_get() and module_put() function sample. ");
MODULE_VERSION("1.0.0.build011819");

#define	DRIVER_NAME	"example"

static int hello_init(void)
{
	printk(KERN_INFO "%s driver installed (before: Reference Count: %d). \n", DRIVER_NAME, module_refcount(THIS_MODULE));
	try_module_get(THIS_MODULE);
	printk(KERN_INFO "%s driver installed (after: Reference Count: %d). \n", DRIVER_NAME, module_refcount(THIS_MODULE));
	// 要記得用module_put()函式來減少參考計數，要不然會無法卸載模組！
	module_put(THIS_MODULE);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "%s driver uninstalled (Reference Count: %d). \n", DRIVER_NAME, module_refcount(THIS_MODULE));
//	module_put(THIS_MODULE);
//	printk(KERN_INFO "%s driver uninstalled (after: Reference Count: %d). \n", DRIVER_NAME, module_refcount(THIS_MODULE));

	return;
}

module_init(hello_init);
module_exit(hello_exit);
