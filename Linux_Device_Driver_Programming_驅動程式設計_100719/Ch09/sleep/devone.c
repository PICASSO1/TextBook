
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
 * 1. 這一支程序展現了"sleep"的用法；
 * 2. sleep只能用在Process Context (Module and System Call Entry Point)，因為sleep睡著了之後，就再也叫不起來了，不可以用在Interrupt Context。
 * 3. 但有一個問題：ssleep()和msleep()裡面可以分別填上"秒數"和"微秒數"；可是「sleep後就起不來了，那填秒數的意義何在？」？？
 *
 * 4. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("(s/m)sleep sample. ");
MODULE_VERSION("1.0.0.build122518");

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (%s); jiffies: %lu \n", __FUNCTION__, jiffies);

	ssleep(1);			// Unit: second (秒)，1
	msleep(1000);		// Unit: micro (微秒)，10 ^ (-6) = 0.000001

	printk(KERN_ALERT "devone driver install (%s); jiffies: %lu (HZ: %d) \n", __FUNCTION__, jiffies, HZ);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (%s). \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
