
/**
 * File Name: wakeup.c
 *
 * CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121418
 *
 * Date: 2018 / 12 / 14
 *
 * Description: 
 * 1. 請參考sleepon.c。
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

extern wait_queue_head_t picasso_sample_wait;

static int hello_init(void)
{
	wait_queue_head_t *wq = &picasso_sample_wait;

	printk(KERN_ALERT "%s: wakeup driver install!! \n", __FUNCTION__);

	wake_up(wq);

	return 0;
}

// "rmnod"的Entry Point (進入點)！
static void hello_exit(void)
{
	printk(KERN_ALERT "%s: wakeup driver uninstall. \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
