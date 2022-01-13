
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011119
 *
 * Date: 2019 / 01 / 11
 *
 * Description: 
 * 1. 這是一個很簡單的Interval Timer (定時呼叫) -- 每隔一段時間就呼叫一次！
 * 2. 範例程式是每10秒就呼叫一次example_timeout函式。
 * 3. 假如在卸載驅動程式的時候：
 *     a). 還有TimeOut函式還沒被呼叫；
 *     b). 正在執行中的TimeOut函式。
 *     此時，就不能使用一般的del_timer()函式；而要使用del_timer_sync()函式。
 * 4. 在使用del_timer_sync()函式時要注意：
 *     a). 不能在Interrupt Context之內呼叫；
 *     b). 不能在拿著Spin Lock的時候呼叫。
 * 5. 如果有定義CONFIG_SMP，del_timer_sync()函式會呼叫del_timer()函式；
 *     如果沒有定義CONFIG_SMP，del_timer_sync()函式會呼叫try_to_del_timer_sync()函式。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("interval_timer (定時呼叫) sample. ");
MODULE_VERSION("1.0.0.build011119");

#define	TIMEOUT_VALUE	(10 * HZ)

static struct timer_list example;

static void example_timeout(unsigned long arg)
{
	struct timer_list *ptr = (struct timer_list *)arg;
	int ret = mod_timer(ptr, jiffies + TIMEOUT_VALUE);	// TimeOut函式被叫之後，下一個10秒鐘再執行一次。

	printk(KERN_INFO "%s: ptr: 0x%p; jiffies: %lu. \n", __FUNCTION__, ptr, jiffies);

	return;
}

static int hello_init(void)
{
	init_timer(&example);							// 初始化struct timer_list，要用這個函式
	example.function = example_timeout;				// 計時器的時間到了要執行的函式
	example.data = (unsigned long)&example;			// 把初始化過後的struct timer_list設給data
	example.expires = jiffies + TIMEOUT_VALUE;			// 10秒過後才要執行
	add_timer(&example);							// 新增一個計時器設定

	printk(KERN_INFO "example driver (%s) installed (jiffies: %lu). \n", __FUNCTION__, jiffies);

	return 0;
}

static void hello_exit(void)
{
	int ret = del_timer_sync(&example);				// 卸載驅動程式的時候要記得執行del_timer()

	printk(KERN_INFO "example driver (%s) uninstalled (ret = %d). \n", __FUNCTION__, ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
