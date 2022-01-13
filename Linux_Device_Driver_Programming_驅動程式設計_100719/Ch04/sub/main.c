
/**
 * File Name: hello.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build112018
 *
 * Date: 2018 / 11 / 20
 *
 * Description: 
 * 1. This is a PostScript for C Language....
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

extern void sub(void);

static int hello_init(void)
{
	printk(KERN_INFO "Hello!! \n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "World!! \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
