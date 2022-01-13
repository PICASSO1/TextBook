
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
 * 1. 這一個範例是原創的，展現了sleep_on()和wake_up()函式的用法；sleep_on()和wake_up()一定要成對出現。
 * 
 * 2. 這一組函式只能用在Process Context，不可以用在Interrupt Context。因為Interrupt Context是屬於「Non-Preemptive (不可被中斷的)」，一執
 *     行之後就沒辦法再被喚醒了。
 * 
 * 3. 這一個範例的執行程序是一進入Module Point Entry之後就會先建立一個kthread，用來執行sleep_on()函式 (sleep_on_kthrFunC)；接著再建立另一
 *     個kthread，用來執行wake_up()函式 (wake_up_kthrFunC)。所以執行結果會像下面這樣：
 * 
 *     hello_init: create the sleep_on_kthr (PID: 5764)                                    // 先建立sleep_on_kthrFunC
 *     sleep_on_kthrFunC (5764): before sleep_on() (jiffies: 4199104) ....       // 一執行sleep_on_kthrFunC之後，就立刻進入睡眠
 *     hello_init: create the wake_up_kthr (PID: 5766)                                    // 接著再建立wake_up_kthrFunC
 *     example driver installed. 
 *     wake_up_kthrFunC (5766): before wake_up() (jiffies: 4202105) .... 
 *     wake_up_kthrFunC (5766): after wake_up() (jiffies: 4202105) ....          // 進入wake_up_kthrFunC之後，原本的睡眠狀態就會被喚醒
 *     sleep_on_kthrFunC (5764): after sleep_on() (jiffies: 4202105) ....          // 被喚醒之後的訊息才會出現！
 *     example driver uninstalled (wake_up_kthr: 0; sleep_on_kthr: 0).
 * 
 *     由執行結果可知，執行sleep_op()時有進入睡眠狀態；執行到wake_up()時也有把原本進入睡眠狀態的程序喚醒。
 *     不過這個範例很奇怪，照理說用sleep_on()入睡只能用wake_up()喚醒；但這裡用wake_up_interruptible()函式也行！？
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
MODULE_DESCRIPTION("sleep_on() and wake_up() feature sample. ");
MODULE_VERSION("1.0.0.build012519");

#define	DRIVER_NAME	"example"

static struct task_struct *sleep_on_kthr = (struct task_struct *)NULL;
wait_queue_head_t example_wq; 
static struct task_struct *wake_up_kthr = (struct task_struct *)NULL;

#define	WAKE_UP_TYPE	2	// 0: by TimeOut; 1: by Signal; 2: by wake_up(); 3: by wake_up_interruptible(); 

static int sleep_on_kthrFunC(void *num)
{
	printk(KERN_INFO "%s (%d): before sleep_on() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	sleep_on(&example_wq);
	printk(KERN_INFO "%s (%d): after sleep_on() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	// 建立kthread之後，要持續地讓它運作，不能一下子就執行kthread_should_stop(); 然後就離開函式，要不然有很大的機率會出現Kernel Oops!! 
	while (1) {
		msleep(100);
		if (kthread_should_stop() == 1)
			break;
	}
	
	return 0;
}

static int wake_up_kthrFunC(void *num)
{
/*	pid_t sleep_on_kthr_pid = *((pid_t *)num);
	// 因為建立kthread的函式所傳進來的參數是「void *num」代表「num這一塊記憶體位址是指到(void *)的資料型態」。所以，要先把
	//「指到num這一塊記憶體位址的"指標"由原本的(void *)轉型為(pid_t *)」即「(pid_t *)num」，再用指標存取符「*()」去存取這一塊記憶體位址。
	struct task_struct *pTask_sleep_on = pid_task(find_vpid((int)sleep_on_kthr_pid), PIDTYPE_PID);

//	printk(KERN_INFO "%s (%d): sleep_on_kthr PID: %d \n", __FUNCTION__, current->pid, (int)sleep_on_kthr_pid);
*/
#if (WAKE_UP_TYPE == 0)
	printk(KERN_INFO "%s (%d): wake up kthread by TimeOut (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 1)
	printk(KERN_INFO "%s (%d): wake up kthread by SIGUSR1 (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 2)
	printk(KERN_INFO "%s (%d): before wake_up() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	wake_up(&example_wq);
	printk(KERN_INFO "%s (%d): after wake_up() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
#elif (WAKE_UP_TYPE == 3)
	printk(KERN_INFO "%s (%d): before wake_up_interruptible() (jiffies: %ld) .... \n", __FUNCTION__, current->pid, jiffies);
	wake_up_interruptible(&example_wq);
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
	wake_up_kthr = kthread_run(wake_up_kthrFunC, (void *)&(sleep_on_kthr->pid), "wake_up_kthr");
	if (IS_ERR(wake_up_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (wake_up_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(wake_up_kthr);
	}
	printk(KERN_INFO "%s: create the wake_up_kthr (PID: %d) \n", __FUNCTION__, (int)wake_up_kthr->pid);
/*	kthread_run()的第2個參數是「void *data」，而"sleep_on_kthr->pid"是1個"數值 (pid_t)"，所以
	必須把儲存"sleep_on_kthr->pid"的記憶體位址「&(sleep_on_kthr->pid)」由原本的「指到(pid_t *)」轉型為「指到(void *)」。
*/	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

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
