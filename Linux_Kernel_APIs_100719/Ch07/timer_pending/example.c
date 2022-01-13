
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011419
 *
 * Date: 2019 / 01 / 14
 *
 * Description: 
 * 1. 這一支程式是從del_timer_sync()修改而來；此處新增了一個timer_pending()的函式，函式原型如下：
 * 2. static inline int timer_pending(const struct timer_list *timer)
 *     {
 *         return (timer->entry.next != NULL);
 *     }
 * 3. 從函式的內容可以得知，若計時器 (Timer)尚未到期 (還在執行中)，回覆true (1)；
 * 4. 反之，若計時器已到期 (執行完畢)，則是回覆false (0, NULL != NULL)。
 * 5. timer_pending()函式似乎是linux-2.4.x在用的；現在linux-2.6.x則是用del_timer_sync()居多.... 
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("timer_pending() sample. ");
MODULE_VERSION("1.0.0.build011419");

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
	example.function = example_timeout;			// 計時器的時間到了要執行的函式
	example.data = (unsigned long)&example;		// 把初始化過後的struct timer_list設給data
	example.expires = jiffies + TIMEOUT_VALUE;		// 10秒過後才要執行
	add_timer(&example);							// 新增一個計時器設定

	printk(KERN_INFO "example driver (%s) installed (jiffies: %lu). \n", __FUNCTION__, jiffies);

	return 0;
}

static void hello_exit(void)
{
	int ret = timer_pending(&example);

	if (ret == 0)
		del_timer(&example);
	else // if (ret == 1)
		del_timer_sync(&example);

	printk(KERN_INFO "example driver (%s) uninstalled (ret = %d). \n", __FUNCTION__, ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
