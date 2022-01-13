
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
 * 1. 相對於「不可以被中斷」 (Non-Interruptible)的ssleep()和msleep()函式，msleep_interruptible()是屬於可以被中斷的 (Interruptible)。
 * 2. msleep_interruptible()函式執行的過程中，若是沒有被中斷，回傳值是0；若是有被中斷，回傳值則是"剩餘的微秒數"。
 *
 * 3. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("msleep_interruptible() sample. ");
MODULE_VERSION("1.0.0.build122518");

static int hello_init(void)
{
	unsigned long ret = 0UL;

	printk(KERN_ALERT "devone driver install (%s); jiffies: %lu (HZ: %d) \n", __FUNCTION__, jiffies, HZ);
	ret = msleep_interruptible(10 * 1000);		// sleep 10 seconds
	printk(KERN_ALERT "%lu (HZ: %d): %s (ret = %lu) \n", jiffies, HZ, (ret == 0)? "TimeOut": "Interrupt", ret);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (%s). \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
