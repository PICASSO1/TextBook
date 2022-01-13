
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122518
 *
 * Date: 2018 / 12 / 25
 *
 * Description: 
 * 1. 這一個範例很簡單，展現Kernel Space裡的另一個時間觀念--"jiffies". 
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("jiffies sample. ");
MODULE_VERSION("1.0.0.build122518");

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (%s); jiffies: %lu \n", __FUNCTION__, jiffies);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (%s). \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
