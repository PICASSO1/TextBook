
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012819
 *
 * Date: 2019 / 01 / 28
 *
 * Description: 
 * 1. Linux的開發者有提到：
 *     These are the old interfaces to sleep waiting for an event. They are racy.  DO NOT use them, use the wait_event* interfaces above.
 *     We plan to remove these interfaces. (對一個事件的"睡眠", "等待"而言，這些是舊的界面。他們很活躍。"不要"使用他們，爾後改使用wait_event*()
 *     一系列的函式。我們計畫移除這些界面。)
 * 
 * 2. 所以，「sleep_on()和wake_up()搭配」的"一系列"函式，在爾後的Linux Kernel更新版本就會移除，取而代之的是wait_event*()一系列的巨集：
 *     a). void sleep_on(wait_queue_head_t *q); 
 *     b). void interruptible_sleep_on(wait_queue_head_t *q); 
 *     c). long sleep_on_timeout(wait_queue_head_t *q, signed long timeout); 
 *     d). long interruptible_sleep_on_timeout(wait_queue_head_t *q, signed long timeout); 
 *     e). #define wake_up(x)                             __wake_up(x, TASK_NORMAL, 1, NULL)
 *     f). #define wake_up_interruptible(x)        __wake_up(x, TASK_INTERRUPTIBLE, 1, NULL)
 *     g). void __wake_up(wait_queue_head_t *q, unsigned int mode, int nr, void *key);
 * 
 *     換成：
 *     a). #define	wait_event(wq, condition)
 *     b). #define	wait_event_interruptible(wq, condition)
 *     c). #define	wait_event_timeout(wq, condition, timeout)
 *     原型：long wait_event_timeout(wait_queue_head_t wq, condition, long timeout); 
 *     d). #define	wait_event_interruptible_timeout(wq, condition, timeout)
 *     原型：long wait_event_interruptible_timeout(wait_queue_head_t wq, condition, long timeout); 
 *
 * 3. 執行結果：
 *     a) 使用wake_up(); 或wake_up_interruptible(); 函式，且條件成立 (condition == 1; )時，wait_event_interruptible(); 會被喚醒。
 *     b) 若只有條件成立 (condition == 1; )而不使用wake_up(); 或wake_up_interruptible(); 函式，則不會被喚醒。
 *     c) 若接收到信號 (Signal) (IS_CONDITION == 1)也會被喚醒，既使條件不成立 (condition == 1; )。
 *     d) 結論：wait_event_interruptible(); 函式，Signal的優先權大於Condition，既使條件不成立，只要接收到信號就會被喚醒！
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
MODULE_DESCRIPTION("wait_event_interruptible() function sample. ");
MODULE_VERSION("1.0.0.build012819");

#define	DRIVER_NAME	"example"

static struct task_struct *wait_event_kthr = (struct task_struct *)NULL;
wait_queue_head_t example_wq; 
static struct task_struct *condition_kthr = (struct task_struct *)NULL;
static int condition = -2;

#define	IS_CONDITION		1	
/* 
0: by TimeOut; 
1: by Signal; 
2: by TRUE (1) condition; 
3: by __wake_up(TASK_NORMAL); 
4: by __wake_up(TASK_INTERRUPTIBLE); 
*/
static int wait_event_kthrFunC(void *num)
{
	condition = 0;
	allow_signal(SIGUSR1);
	printk(KERN_INFO "%s (%d): before wait_event_interruptible() (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
	wait_event_interruptible(example_wq, condition);
	printk(KERN_INFO "%s (%d): after wait_event_interruptible() (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);

	while (1) {
		msleep(100);
		if (kthread_should_stop() == 1)
			break;
	}
	
	return 0;
}

static int condition_kthrFunC(void *num)
{
#if (IS_CONDITION == 0)
	printk(KERN_INFO "%s (%d): __wake_up() kthread by TimeOut (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
#elif (IS_CONDITION == 1)
	printk(KERN_INFO "%s (%d): __wake_up() kthread by SIGUSR1 (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
#elif (IS_CONDITION == 2)
	condition = 1;
	printk(KERN_INFO "%s (%d): __wake_up() kthread by TRUE (1) condition (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
#elif  (IS_CONDITION == 3)
	printk(KERN_INFO "%s (%d): before __wake_up(TASK_NORMAL) (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
	condition = 1;
	__wake_up(&example_wq, TASK_NORMAL, 1, NULL); 
	printk(KERN_INFO "%s (%d): after __wake_up(TASK_NORMAL) (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
#elif  (IS_CONDITION == 4)
	printk(KERN_INFO "%s (%d): before __wake_up(TASK_INTERRUPTIBLE) (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
	condition = 1;
	__wake_up(&example_wq, TASK_INTERRUPTIBLE, 1, NULL); 
	printk(KERN_INFO "%s (%d): after __wake_up(TASK_INTERRUPTIBLE) (jiffies: %ld; condition = %d) .... \n", __FUNCTION__, current->pid, jiffies, condition);
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
	// Create a kthread for "Wait Event" ....
	wait_event_kthr = kthread_create(wait_event_kthrFunC, (void *)NULL, "wait_event_kthr");
	if (IS_ERR(wait_event_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (wait_event_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(wait_event_kthr);
	}
	wake_up_process(wait_event_kthr);
	printk(KERN_INFO "%s: create the wait_event_kthr (PID: %d) \n", __FUNCTION__, (int)wait_event_kthr->pid);

	ssleep(3); 
	// Create a kthread for "Condition" ....
	condition_kthr = kthread_run(condition_kthrFunC, (void *)NULL, "condition_kthr");
	if (IS_ERR(condition_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (condition_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(condition_kthr);
	}
	printk(KERN_INFO "%s: create the condition_kthr (PID: %d) \n", __FUNCTION__, (int)condition_kthr->pid);

	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	int ret_condition = -1, ret_wait_event = -1;
	
	if (IS_ERR(condition_kthr) == 0)
		ret_condition = kthread_stop(condition_kthr);

	if (IS_ERR(wait_event_kthr) == 0)
		ret_wait_event = kthread_stop(wait_event_kthr);

	printk(KERN_INFO "%s driver uninstalled (condition_kthr: %d; wait_event_kthr: %d). \n", \
		DRIVER_NAME, ret_condition, ret_wait_event);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
