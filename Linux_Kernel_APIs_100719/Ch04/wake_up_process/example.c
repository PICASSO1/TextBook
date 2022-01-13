
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
 * 1. 這一支程序是從/Ch03/kthread_run/修改而來；用kthread_create()和wake_up_process()這2支函式取代原本的kthread_run()，執行結果完全一樣！
 * 2. int wake_up_process(struct task_struct *tsk); 
 *     wake_up_process()函式用來喚醒處於睡眠狀態的處理程序，使處理程序由睡眠狀態變為RUNNING (執行中)狀態，從而能夠被CPU重新排程執行。
 * 3. 在這裡，wake_up_process()函式用來喚醒一個kthread。
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
	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: kernel thread leave!! \n", __FUNCTION__);

	return 0;
}

static int hello_init(void)
{
	pid_t pid = (pid_t)0;
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	example_kthread = kthread_create(kthread_function, NULL, "ex_kthread_%d", 4);
	if (IS_ERR(example_kthread) != 0) {
		printk(KERN_ERR "%s driver kthread failed!! \n", DRIVER_NAME);
		return PTR_ERR(example_kthread);
	}
	wake_up_process(example_kthread);

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
