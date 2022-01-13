
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012219
 *
 * Date: 2019 / 01 / 22
 *
 * Description: 
 * 1. 這一支程序是從/Ch03/signal_pending/修改而來的。
 * 2. ssleep()和msleep()是屬於「不可以被中斷」 (Non-Interruptible)的函式，進入睡眠狀態之後，要等到設定的秒數到期，程序才會醒來。
 * 3. 而msleep_interruptible()函式則是屬於「可以被中斷」 (Interruptible)；這裡的中斷，指的是被信號 (Signal)中斷。
 * 4. 假如有被Signal中斷，msleep_interruptible()函式的回傳值為剩餘的秒數；否則回傳0。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("msleep_interruptible() function sample. ");
MODULE_VERSION("1.0.0.build012219");

#define	DRIVER_NAME	"example"

static struct task_struct *example_kthread = (struct task_struct *)NULL;

static int kthread_function(void *num)
{
	int ret = -1;

	printk(KERN_INFO "%s: kernel thread running.... \n", __FUNCTION__);

	allow_signal(SIGKILL);
	do {
		ret = msleep_interruptible(1000);
		if (ret != 0)
			break;
	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: kernel thread leave (status: %s (ret = %d))!! \n", __FUNCTION__, (ret == 0)? "TimeOut": "Interrupt", ret);

	return 0;
}

static int hello_init(void)
{
	pid_t pid = (pid_t)0;
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	example_kthread = kthread_run(kthread_function, NULL, "kthr_sig_%d", 3);
	if (IS_ERR(example_kthread) != 0) {
		printk(KERN_ERR "%s driver kthread failed!! \n", DRIVER_NAME);
		return PTR_ERR(example_kthread);
	}

	pid = example_kthread->pid;
	printk(KERN_INFO "%s driver installed (example_kthread->pid = %d). \n", DRIVER_NAME, (int)example_kthread->pid);

	return 0;
}

static void hello_exit(void)
{
	int ret = -1;

	if (IS_ERR(example_kthread) == 0) {
		ret = kthread_stop(example_kthread);
		printk(KERN_INFO "%s driver uninstalled (ret = %d). \n", DRIVER_NAME, ret);
	}

	return;
}

module_init(hello_init);
module_exit(hello_exit);
