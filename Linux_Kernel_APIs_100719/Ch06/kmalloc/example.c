
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build010919
 *
 * Date: 2019 / 01 / 09
 *
 * Description: 
 * 1. 這一支程序展現了在Linux Kernal Space中，動態取得記憶體最常見的方式：kmalloc()和kfree()。
 * 2. kmalloc()函式取得記憶體的建議大小是128KB，但現在的系統已經可以延展至32MB。
 * 3. kmalloc()和kfree()是Slab Allocator實作出來的介面函式，「且能保證取得"實體記憶體"上連續的記憶體位址」。
 * 4. static inline void *kzalloc(size_t size, gfp_t flags); kzalloc()函式的用法和kmalloc()完全一模一樣，差異在於kzalloc()在配置完記憶體空間之後，
 *     還會全部初始化為0x00 (Zero Allocate)。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("kmalloc(), kzalloc() and kfree() sample. ");
MODULE_VERSION("1.0.0.build010919");

void *example = (void *)NULL;

static int hello_init(void)
{
	void *ptr = (void *)NULL;

	printk(KERN_INFO "example (kmalloc(), kzalloc() and kfree()) driver install. \n");
//	example = ptr = kmalloc(2, GFP_KERNEL);
	example = ptr = kzalloc(2, GFP_KERNEL);	// Get Free Page
	printk(KERN_INFO "ptr = 0x%p; example = 0x%p \n", ptr, example);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example (kmalloc(), kzalloc() and kfree()) driver uninstall. \n");
	kfree((void *)example);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
