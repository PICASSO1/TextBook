
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122318
 *
 * Date: 2018 / 12 / 23
 *
 * Description: 
 * 1. 這一支程序沒什麼，如果使用kmalloc()之後，沒有使用kfree()，就會導致於Memory Leak。這個範例呈現了這個問題。
 * 2. 如果有問題的話就重新開機吧！
 *
 * 3. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("Memory Leak sample. ");
MODULE_VERSION("1.0.0.build122318");

void *ptr = (void *)NULL; 

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (Memory Leak). \n");
	ptr = (void *)kmalloc(32, GFP_KERNEL);
	printk(KERN_ALERT "ptr = 0x%p \n", ptr);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (Memory Leak). \n");
	// ERROR!! Need to free this pointer; but we don't do it!! 
//	kfree((void *)ptr);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
