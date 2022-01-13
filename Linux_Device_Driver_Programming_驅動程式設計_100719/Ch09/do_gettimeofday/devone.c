
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
 * 1. 從第9章開始在講的是Timer Entry Point的寫法。
 * 2. 這一個範例是介紹do_gettimeofday()函式的用法--就是取得現在的時間；但就實務經驗上很少會在Kernel Space取得現在的時間。
 *
 * x. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("do_gettimeofday() sample. ");
MODULE_VERSION("1.0.0.build122318");

static int hello_init(void)
{
	struct timeval now;
	time_t diff0;				// time_t: 秒。
	suseconds_t diff1;			// suseconds_t: 微秒，10的-6次方，百萬分之一秒，1 / 100,0000
	volatile int i = -1;

	printk(KERN_ALERT "devone driver install (%s). \n", __FUNCTION__);
	do_gettimeofday(&now);		// 取得現在的時間
	diff0 = now.tv_sec;			// 把"秒"的部份取出來；
	diff1 = now.tv_usec;		// 把"微秒"的部份取出來；
	printk(KERN_ALERT "Current UTC: seconds: %lu (microseconds: %lu) \n", now.tv_sec, now.tv_usec);
	for (i = 0; i < 9999; i++)	// 做一些雜事....
		;
	do_gettimeofday(&now);		// 再抓一次時間....
	diff0 = now.tv_sec - diff0;	// 計算出時間"秒"的差值。
	diff1 = now.tv_usec - diff1;	// 計算出時間"微秒"的差值。
	printk(KERN_ALERT "Elapsed time: seconds: %lu (microseconds: %lu) \n", diff0, diff1);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall (%s). \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
