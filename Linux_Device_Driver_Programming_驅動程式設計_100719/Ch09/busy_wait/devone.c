
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
 * 1. 這一支程序展現了"delay"的用法；
 * 2. delay只能用在Interrupt Context (Timer and Interrupt Entry Point)，因為delay是屬於Busy-Wait (忙碌等待)，一使用之後整個Kernel Space CPU都會被handle住
 *     ，無法執行其他任務，而且delay的時間要越短越好，最好不要超1秒鐘。
 * 3. delay「不適合」應用在Process Context。
 *
 * 4. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("busy-wait (delay) sample. ");
MODULE_VERSION("1.0.0.build122518");

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (%s); jiffies: %lu \n", __FUNCTION__, jiffies);

	mdelay(1000);		// Unit: milli (毫)，10 ^ (-3) = 0.001
	udelay(1000);			// Unit: micro (微)，10 ^ (-6) = 0.000001
	ndelay(1000);			// Unit: nano (奈)，10 ^ (-9) = 0.000000001
	
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
