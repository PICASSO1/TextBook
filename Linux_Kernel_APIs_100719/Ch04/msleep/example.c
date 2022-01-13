
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012119
 *
 * Date: 2019 / 01 / 21
 *
 * Description: 
 * 1. static inline void ssleep(unsigned int seconds) { msleep(seconds * 1000); }
 * 2. void msleep(unsigned int msecs);
 * 3. 這2支函式只能用在Process Context；前者的單位為秒 (Second)，後者的單位為毫秒 (Micro Second, 10 ^ -3 = 0.001)。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/jiffies.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("msleep() function sample. ");
MODULE_VERSION("1.0.0.build012119");

#define	DRIVER_NAME	"example"

static int hello_init(void)
{
	printk(KERN_INFO "%s driver installed (before msleep(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	msleep(1000);
	printk(KERN_INFO "%s driver installed (after msleep(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
