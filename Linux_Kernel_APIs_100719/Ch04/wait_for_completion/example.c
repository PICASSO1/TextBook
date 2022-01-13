
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012119
 *
 * Date: 2019 / 01 / 21
 *
 * Description: 
 * 1. 
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/wait.h>
#include <linux/completion.h>
#include <asm/current.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("*() function sample. ");
MODULE_VERSION("1.0.0.build012119");

#define	DRIVER_NAME	"example"

static struct task_struct *wait_kthread = (struct task_struct *)NULL;
static struct task_struct *comp_kthread = (struct task_struct *)NULL;

static struct completion comp;

//static wait_queue_head_t wait;

static int wait_kthrFunC(void *num)
{
	int ret = -1;

	allow_signal(SIGUSR1);	
	do {
		msleep(1000);
	} while (signal_pending(current) == 0);
	printk(KERN_INFO "Fuck!! I got a Signal!! \n");

	do {
		msleep(1000);
	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: PID = %d \n", __FUNCTION__, (int)current->pid);

	return 0;
}

static int comp_kthrFunC(void *num)
{
	do {
		msleep(1000);
	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: PID = %d \n", __FUNCTION__, (int)current->pid);

	return 0;
}

static int hello_init(void)
{
	init_completion(&comp);

	wait_kthread = kthread_run(wait_kthrFunC, (void *)NULL, "wait_kthr");
	if (IS_ERR(wait_kthread) != 0) {
		printk(KERN_ERR "%s driver kthread (wait_kthread) failed!! \n", DRIVER_NAME);
		return PTR_ERR(wait_kthread);
	}

	ssleep(3);

	comp_kthread = kthread_run(comp_kthrFunC, (void *)NULL, "comp_kthr");
	if (IS_ERR(comp_kthread) != 0) {
		printk(KERN_ERR "%s driver kthread (comp_kthread) failed!! \n", DRIVER_NAME);
		return PTR_ERR(comp_kthread);
	}
	
	printk(KERN_INFO "%s driver installed (PID: %d; wait_kthrFunC: %d; comp_kthrFunC: %d). \n", DRIVER_NAME, \
		current->pid, (int)wait_kthread->pid, (int)comp_kthread->pid);

	return 0;
}

static void hello_exit(void)
{
	int comp_ret = -1, wait_ret = -1;

	if (IS_ERR(comp_kthread) == 0)
		comp_ret = kthread_stop(comp_kthread);

	if (IS_ERR(wait_kthread) == 0)
		wait_ret = kthread_stop(wait_kthread);

	printk(KERN_INFO "%s driver uninstalled (comp_ret = %d; wait_ret = %d). \n", DRIVER_NAME, comp_ret, wait_ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
