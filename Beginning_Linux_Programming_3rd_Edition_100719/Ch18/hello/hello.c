
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

#include <linux/kernel.h>

static int init_module(void)
{
	printk(KERN_INFO "Hello!! World!! \n");

	return 0;
}

static void cleanup_module(void)
{
	printk(KERN_INFO "Good-Bye!! \n");

	return;
}
