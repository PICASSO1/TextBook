
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122218
 *
 * Date: 2018 / 12 / 22
 *
 * Description: 
 * 1. 這一支程序展現了在Linux Kernal Space中，動態取得記憶體最常見的方式：kmalloc()和kfree()。
 * 2. kmalloc()函式取得記憶體的建議大小是128KB，但現在的系統已經可以延展至32MB。
 * 3. kmalloc()和kfree()是Slab Allocator實作出來的介面函式，「且能保證取得"實體記憶體"上連續的記憶體位址」。
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("kmalloc() and kfree() sample. ");
MODULE_VERSION("1.0.0.build122218");

void *devone = (void *)NULL;

static int hello_init(void)
{
	void *ptr = (void *)NULL;

	printk(KERN_ALERT "devone driver install. \n");
	devone = ptr = (void *)kmalloc(2, GFP_KERNEL);	// Get Free Page
	printk(KERN_ALERT "ptr = 0x%p; devone = 0x%p \n", ptr, devone);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
	kfree((void *)devone);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
