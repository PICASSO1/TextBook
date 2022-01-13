
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011519
 *
 * Date: 2019 / 01 / 15
 *
 * Description: 
 * 1. 這一個範例是介紹do_gettimeofday()函式的用法--就是取得現在的時間；但就實務經驗上很少會在Kernel Space取得現在的時間。
 * 2. 
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("do_gettimeofday() sample. ");
MODULE_VERSION("1.0.0.build011519");

static int hello_init(void)
{
	struct timeval now = {	// 宣告一個一個時間結構 (Time Value)且初始化為0
		.tv_sec = 0, 			// time_t: 秒。
		.tv_usec = 0			// suseconds_t: 微秒，10的-6次方，百萬分之一秒，1 / 100,0000
	};

	printk(KERN_INFO "example driver (%s) installed. \n", __FUNCTION__);
	do_gettimeofday(&now);	// 取得自1970 / 01 / 01 00:00:00到現在的秒數
	printk(KERN_NOTICE "The seconds of the day is: %ld. \n", now.tv_sec);
	printk(KERN_NOTICE "The microseconds of the day is: %ld. \n", now.tv_usec);
	printk(KERN_INFO "do_gettimeofday() feature testing done. \n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example driver (%s) uninstalled. \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
