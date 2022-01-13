
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
 * 1. 這是一個很簡單的計時器 (Timer)範例程式。
 * 2. 在掛載模組之後，就會啟動計時器，並先列印出當下的jiffies值。
 * 3. 過了10秒之後，執行example_timeout()函式並列印出jiffies值。
 * 4. 最後在卸載模組的時候，使用del_timer()函式，函式的回傳值：
 *     0: 刪除的計時器已經「處於到期函式 (example_timeout)"執行狀態"」或「已經不存在 (函式執行完畢)」，刪除無效；
 *     1: 刪除的計時器正處於啟動狀態，刪除成功。
 * 5. 因為Timer Entry Point是屬於Interrupt Context (軟體中斷)，所以TimeOut的執行函式必須要注意：
 *     a). 不能呼叫會sleep的函式；
 *     b). 不能使用Process Context的Spin Lock；
 *     c). 如果有多個CPU的話，就可能同時執行多個TimeOut函式。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("*_timer() function sample. ");
MODULE_VERSION("1.0.0.build011119");

#define	TIMEOUT_VALUE	(10 * HZ)

static struct timer_list example;

static void example_timeout(unsigned long arg)
{
	struct timer_list *ptr = (struct timer_list *)arg;

	printk(KERN_INFO "%s: ptr: 0x%p; jiffies: %lu. \n", __FUNCTION__, ptr, jiffies);

	return;
}

static int hello_init(void)
{
	init_timer(&example);					// 初始化struct timer_list，要用這個函式
	example.function = example_timeout;		// 計時器的時間到了要執行的函式
	example.data = (unsigned long)&example;	// 把初始化過後的struct timer_list設給data
	example.expires = jiffies + TIMEOUT_VALUE;	// 10秒過後才要執行
	add_timer(&example);					// 新增一個計時器設定

	printk(KERN_INFO "example driver (%s) installed (jiffies: %lu). \n", __FUNCTION__, jiffies);

	return 0;
}

static void hello_exit(void)
{
	int ret = del_timer(&example);			// 卸載驅動程式的時候要記得執行del_timer()

	printk(KERN_INFO "example driver (%s) uninstalled (ret = %d). \n", __FUNCTION__, ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
