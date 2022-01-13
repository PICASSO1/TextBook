
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
 * 1. 這是一個很簡單的計時器範例程式；就照這個範例寫即可。
 * 2. 假如在卸載驅動程式的時候：
 *     a). 還有TimeOut函式還沒被呼叫；
 *     b). 正在執行中的TimeOut函式。
 *     此時，就不能使用一般的del_timer()函式；而要使用del_timer_sync()函式。
 * 3. 在使用del_timer_sync()函式時要注意：
 *     a). 不能在Interrupt Context之內呼叫；
 *     b). 不能在拿著Spin Lock的時候呼叫。
 * 4. 因為Timer Entry Point是屬於Interrupt Context (軟體中斷)，所以TimeOut的執行函式必須要注意：
 *     a). 不能呼叫會sleep的函式；
 *     b). 不能使用Process Context的Spin Lock；
 *     c). 如果有多個CPU的話，就可能同時執行多個TimeOut函式。
 *
 * 5. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("timer (計時器) sample. ");
MODULE_VERSION("1.0.0.build122618");

#define	TIMEOUT_VALUE	(10 * HZ)

static struct timer_list tickfn;

static void devone_timeout(unsigned long arg)
{
	struct timer_list *ptr = (struct timer_list *)arg;

	printk(KERN_ALERT "ptr: 0x%p (%s) \n", ptr, __FUNCTION__);

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
