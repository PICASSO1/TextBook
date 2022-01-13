
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012519
 *
 * Date: 2019 / 01 / 25
 *
 * Description: 
 * 1. 這一程序是從「sleep_on() / wake_up()」的範例修改而來的。
 * 
 * 2. 原本的sleep_on()改成用sleep_on_timeout()，它的用法是：程序進入睡眠狀態之後，時間到了就會被喚醒，也可以被wake_up()喚醒；但是wake_up_i
 *     nterruptible()則是無法喚醒。
 * 
 * 3. sleep_on_timeout()函式的第2個參數，是要自動醒來的毫秒數 (0.001秒)；若是在中途被wake_up()喚醒，則是回傳剩餘的毫秒數。
 * 
 * 4. 除此之外，還有一系列的相關函式如下：
 *     void sleep_on(wait_queue_head_t *q);
 *     會讓原本程序的狀態 (state)設定成TASK_UNINTERRUPTIBLE (不可被中斷的)，一定要和wake_up()一起搭配才能夠喚醒。
 * 
 *     void interruptible_sleep_on(wait_queue_head_t *q);
 *     會讓原本程序的狀態 (state)設定成TASK_INTERRUPTIBLE (可被中斷的)，可以和wake_up()或是wake_up_interruptible()搭配。
 * 
 *     long sleep_on_timeout(wait_queue_head_t *q, signed long timeout);
 *     會讓原本程序的狀態 (state)設定成TASK_INTERRUPTIBLE (可被中斷的)，進入到睡眠狀態之後，時間到了就會自動醒來；若時間還沒到就被喚醒，
 *     則是會回傳剩餘的時間。
 * 
 *     long interruptible_sleep_on_timeout(wait_queue_head_t *q, signed long timeout);
 *     會讓原本程序的狀態 (state)設定成TASK_INTERRUPTIBLE (可被中斷的)，進入到睡眠狀態之後，接收到信號，或是時間到了之後就會被喚醒。若時間
 *     還沒到就被喚醒，則是會回傳剩餘的時間。
 * 
 *     #define wake_up(x)				__wake_up(x, TASK_NORMAL, 1, NULL)
 *     #define wake_up_interruptible(x)	__wake_up(x, TASK_INTERRUPTIBLE, 1, NULL)
 *     void __wake_up(wait_queue_head_t *q, unsigned int mode, int nr, void *key);
 * 
 * 5. Linux的開發者也有提到：
 *     These are the old interfaces to sleep waiting for an event. They are racy.  DO NOT use them, use the wait_event* interfaces above.
 *     We plan to remove these interfaces. (對一個事件的"睡眠", "等待"而言，這些是舊的界面。他們很活躍。"不要"使用他們，爾後改使用wait_event*()
 *     一系列的函式。我們計畫移除這些界面。)
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/wait.h>
#include <linux/pid.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <linux/jiffies.h>
#include <linux/delay.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("sleep_on_timeout() function sample. ");
MODULE_VERSION("1.0.0.build012519");

#define	DRIVER_NAME	"example"

static struct task_struct *sleep_on_kthr = (struct task_struct *)NULL;
wait_queue_head_t example_wq; 
static struct task_struct *wake_up_kthr = (struct task_struct *)NULL;

#define	WAKE_UP_TYPE	0	// 0: by TimeOut; 1: by Signal; 2: by wake_up(); 3: by wake_up_interruptible(); 

static int sleep_on_kthrFunC(void *num)
{
	long ret = -1L;

	printk(KERN_INFO "%s (%d): before sleep_on_timeout() (jiffies: %ld; ret = %ld) .... \n", __FUNCTION__, current->pid, jiffies, ret);
	ret = sleep_on_timeout(&example_wq, 5000);
	printk(KERN_INFO "%s (%d): after sleep_on_timeout() (jiffies: %ld; ret = %ld) .... \n", __FUNCTION__, current->pid, jiffies, ret);

	while (1) {
		msleep(100);
		if (kthread_should_stop() == 1)
			break;
	}
	
	return 0;
}

static int wake_up_kthrFunC(void *num)
{
#if (WAKE_UP_TYPE == 0)
	printk(KERN_INFO "%s (%d): wake up kthread by TimeOut (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 1)
	printk(KERN_INFO "%s (%d): wake up kthread by SIGUSR1 (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 2)
	printk(KERN_INFO "%s (%d): before wake_up() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	msleep(1000);
	__wake_up(&example_wq, TASK_NORMAL, 1, (void *)NULL); 
	printk(KERN_INFO "%s (%d): after wake_up() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 3)
	printk(KERN_INFO "%s (%d): before wake_up_interruptible() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	msleep(1000);
	__wake_up(&example_wq, TASK_INTERRUPTIBLE, 1, (void *)NULL); 
	printk(KERN_INFO "%s (%d): after wake_up_interruptible() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#else
	
#endif
	while (1) {
		msleep(100);
		if (kthread_should_stop())
			break;
	}
	
	return 0;
}

static int hello_init(void)
{
	init_waitqueue_head(&example_wq);
	// Create a kthread for "Sleep On" ....
	sleep_on_kthr = kthread_create(sleep_on_kthrFunC, (void *)NULL, "sleep_on_kthr");
	if (IS_ERR(sleep_on_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (sleep_on_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(sleep_on_kthr);
	}
	wake_up_process(sleep_on_kthr);
	printk(KERN_INFO "%s: create the sleep_on_kthr (PID: %d) \n", __FUNCTION__, (int)sleep_on_kthr->pid);

	ssleep(3);
	// Create a kthread for "Wake Up" ....
	wake_up_kthr = kthread_run(wake_up_kthrFunC, (void *)NULL, "wake_up_kthr");
	if (IS_ERR(wake_up_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (wake_up_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(wake_up_kthr);
	}
	printk(KERN_INFO "%s: create the wake_up_kthr (PID: %d) \n", __FUNCTION__, (int)wake_up_kthr->pid);

	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	int ret_wake_up = -1, ret_sleep_on = -1;
	
	if (IS_ERR(wake_up_kthr) == 0)
		ret_wake_up = kthread_stop(wake_up_kthr);

	if (IS_ERR(sleep_on_kthr) == 0)
		ret_sleep_on = kthread_stop(sleep_on_kthr);

	printk(KERN_INFO "%s driver uninstalled (wake_up_kthr: %d; sleep_on_kthr: %d). \n", \
		DRIVER_NAME, ret_wake_up, ret_sleep_on);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
