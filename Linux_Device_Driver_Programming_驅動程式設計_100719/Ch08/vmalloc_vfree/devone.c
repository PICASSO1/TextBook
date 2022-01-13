
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
 * 1. 這一支程序展現了在Linux Kernel Space中，動態取得記憶體另一種方式：vmalloc()和vfree()。
 * 2. 相對於kmalloc()和kfree()「能保證取得"實體記憶體"上連續的記憶體位址」；vmalloc()和vfree()則是「保證取得"虛擬記憶體"上連續的記憶體位址」。
 * 3. kmalloc()和kfree()是透過較上層的Slab Allocator實作出來的介面函式；而vmalloc()和vfree()則是直接取用較底層的Buddy System / Allocator。
 * 4. Linux Kernel不建議使用vmalloc()和vfree()函式；使用kmalloc()和kfree()即可！
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("vmalloc() and vfree() sample. ");
MODULE_VERSION("1.0.0.build122218");

void *devone = (void *)NULL;

static int hello_init(void)
{
	void *ptr = (void *)NULL;

	printk(KERN_ALERT "devone driver install. \n");
	devone = ptr = (void *)vmalloc(2);
	printk(KERN_ALERT "ptr = 0x%p; devone = 0x%p \n", ptr, devone);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
	vfree((void *)devone);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
