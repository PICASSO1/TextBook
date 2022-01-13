
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
 * 1. kmalloc()和kfree()是Slab Allocator實作出來的介面函式，「且能保證取得"實體記憶體"上連續的記憶體位址」。
 * 2. 相對於kmalloc()和kfree()「能保證取得"實體記憶體"上連續的記憶體位址」；vmalloc()和vfree()則是「保證取得"虛擬記憶體"上連續的記憶體位址」。
 * 3. kmalloc()和kfree()是透過較上層的Slab Allocator實作出來的介面函式；而vmalloc()和vfree()則是直接取用較底層的Buddy System / Allocator。
 * 4. 若「欲取得的記憶體大小剛好是1 Page」，也可以不透過Slab Allocator的kmalloc()和kfree()函式；而是使用__get_free_pages()和free_pages()函式--就是這一支範例程式。
 *
 * 5. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("__get_free_pages() function sample. ");
MODULE_VERSION("1.0.0.build122318");

void *ptr0 = (void *)NULL; 
void *ptr1 = (void *)NULL;
int order0 = 3;
int order1 = 0;

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (__get_free_pages()). \n");

	ptr0 = (void *)__get_free_pages(GFP_KERNEL, order0);
	if (ptr0 != (void *)NULL)
		printk(KERN_ALERT "2^%d * %ld bytes allocated. \n", order0, PAGE_SIZE);

	order1 = get_order(8000);
	ptr1 = (void *)__get_free_pages(GFP_KERNEL, order1);
	if (ptr1 != (void *)NULL)
		printk(KERN_ALERT "2^%d * %ld bytes allocated. \n", order1, PAGE_SIZE);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (__get_free_pages()). \n");

	if (ptr0 != (void *)NULL)
		free_pages((unsigned long)ptr0, order0);

	if (ptr1 != (void *)NULL)
		free_pages((unsigned long)ptr1, order1);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
