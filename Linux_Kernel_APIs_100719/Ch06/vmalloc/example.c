
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
 * 1. 這一支程序展現了在Linux Kernel Space中，動態取得記憶體另一種方式：vmalloc()和vfree()。
 * 2. 相對於kmalloc()和kfree()「能保證取得"實體記憶體"上連續的記憶體位址」；vmalloc()和vfree()則是「保證取得"虛擬記憶體"上連續的記憶體位址」。
 * 3. kmalloc()和kfree()是透過較上層的Slab Allocator實作出來的介面函式；而vmalloc()和vfree()則是直接取用較底層的Buddy System / Allocator。
 * 4. Linux Kernel不建議使用vmalloc()和vfree()函式；使用kmalloc()和kfree()即可！
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("vmalloc() and vfree() sample. ");
MODULE_VERSION("1.0.0.build010919");

void *example = (void *)NULL;

static int hello_init(void)
{
	void *ptr = (void *)NULL;

	printk(KERN_INFO "example (vmalloc() and vfree()) driver install. \n");
	example = ptr = (void *)vmalloc(2);
	printk(KERN_INFO "ptr = 0x%p; example = 0x%p \n", ptr, example);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example (vmalloc() and vfree()) driver uninstall. \n");
	vfree((void *)example);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
