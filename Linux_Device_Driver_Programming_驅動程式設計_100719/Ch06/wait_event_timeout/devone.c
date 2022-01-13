
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121518
 *
 * Date: 2018 / 12 / 15
 *
 * Description: 
 * 1. 基於"sleep_on_wake_up"的缺點，這一次用wait_event_timeout(); 函式來取代原本的sleep_on(); 。
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

#define	SLEEPON_TIMEOUT		(6 * HZ)
#define	WAKEUP_TIMEOUT		(5 * HZ)

static struct timer_list tickfn;
static wait_queue_head_t wait;
static int condition = 0;

static void devone_timeout(unsigned long arg)
{
	wait_queue_head_t *wq = (wait_queue_head_t *)arg;

	printk(KERN_ALERT "wq: 0x%p (%s) \n", wq, __FUNCTION__);
	condition = 1;
	wake_up(wq);

	return;
}

static int hello_init(void)
{
	long val = 0L;

	printk(KERN_ALERT "Driver install: 0x%p \n", &tickfn);

	init_waitqueue_head(&wait);
	init_timer(&tickfn);						// 初始化一個計時器結構
	tickfn.function = devone_timeout;			// 設定時間到了要執行的函式
	tickfn.data = (unsigned long)&wait;		// 好像要把wait_queue_head_t的資料設給data這個成員.... 
	tickfn.expires = jiffies + WAKEUP_TIMEOUT;	// 設定TimeOut的時間
	add_timer(&tickfn);					// 新增一個計時器

	condition = 0;
	// 用wait_event_timeout()函式來取代sleep_on()
	val = wait_event_timeout(wait, condition, SLEEPON_TIMEOUT);
	if (val == 0)	// timeout
		printk(KERN_ALERT "Timeout ocurred (%s). \n", __FUNCTION__);

	return 0;
}

static void hello_exit(void)
{
	del_timer_sync(&tickfn);
	printk(KERN_ALERT "Driver uninstall. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
