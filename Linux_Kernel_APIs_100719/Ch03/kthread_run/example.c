
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011919
 *
 * Date: 2019 / 01 / 19
 *
 * Description: 
 * 1. 這是一支很簡單的Kernel Thread程序，當安裝完模組之後，就會開始不斷地執行kthread，用"ps aux | tail -n 10"和"dmesg -c"即可查看狀況！
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
MODULE_DESCRIPTION("Kernel Thread sample. ");
MODULE_VERSION("1.0.0.build011919");

#define	DRIVER_NAME	"example"

static struct task_struct *example_kthread = (struct task_struct *)NULL;

static int kthread_function(void *num)
{
	printk(KERN_INFO "%s: kernel thread running.... \n", __FUNCTION__);

	do {
		msleep(1000);
/*		Unit: micro (微秒)，10 ^ (-6) = 0.000001
		經過許多的實驗，在Kernel Space裡跑loop迴圈，裡面要加上一個msleep(1000); 停個兒0.001秒，要不然會Kernel Oops!! 
*/	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: kernel thread leave!! \n", __FUNCTION__);

	return 0;
}

static int hello_init(void)
{
	pid_t pid = (pid_t)0;
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	example_kthread = kthread_run(kthread_function, NULL, "ex_kthread_%d", 3);
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
