
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122618
 *
 * Date: 2018 / 12 / 26
 *
 * Description: 
 * 1. 上一個範例是基本的Timer (計時器)；這一個範例是Interval Timer (定時呼叫) -- 每隔一段時間就呼叫一次！
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("interval_timer (定時呼叫) sample. ");
MODULE_VERSION("1.0.0.build122618");

#define	TIMEOUT_VALUE	(3 * HZ)

static struct timer_list tickfn;

static void devone_timeout(unsigned long arg)
{
	struct timer_list *ptr = (struct timer_list *)arg;
	int ret = mod_timer(ptr, jiffies + TIMEOUT_VALUE);	// TimeOut函式被叫之後，下一個3秒鐘再執行一次。

	printk(KERN_ALERT "mod_timer(): %d (%lu, %s) \n", ret, jiffies, __FUNCTION__);

	return;
}

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install: 0x%p \n", &tickfn);

	init_timer(&tickfn);						// 初始化struct timer_list，要用這個函式
	tickfn.function = devone_timeout;			// 計時器的時間到了要執行的函式
	tickfn.data = (unsigned long)&tickfn;		// 把初始化過後的struct timer_list設給data
	tickfn.expires = jiffies + TIMEOUT_VALUE;	// 10秒過後才要執行
	add_timer(&tickfn);					// 新增一個計時器設定

	return 0;
}

static void hello_exit(void)
{
	int ret = del_timer_sync(&tickfn);			// 卸載驅動程式的時候要記得執行del_timer_sync()

	printk(KERN_ALERT "devone driver uninstall (%d). \n", ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
