
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
 * 1. 因為建立一個kthread，就相當於在User Space建立一個Process，所以也會有一個PID。
 * 2. 既然kthread會有PID，那就表示kthread和User Process一樣，可以設定和接收信號 (Signal)。
 * 3. int allow_signal(int sig); 在kthread中可以允許哪一種信號。
 * 4. static inline int signal_pending(struct task_struct *p); 
 *     假如kthread有接收到allow_signal()所設定的信號，signal_pending()函式的回傳值會是1，否則為0。
 *     參數"struct task_struct *p"設定為"current"即可，表當時這一支kthread。
 * 
 * 5. 這一個範例還可以延展為：
 *     a) 在kthread註冊不同的Signal，當User Process發送不同的信號給kthread時，能做不一樣的事；
 *     b) 能否讓kthread一直接收Signal？
 *     c). kthread如何發送Signal給User Process？
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
MODULE_DESCRIPTION("signal_pending() & allow_signal() sample. ");
MODULE_VERSION("1.0.0.build012119");

#define	DRIVER_NAME	"example"

static struct task_struct *example_kthread = (struct task_struct *)NULL;

static int kthread_function(void *num)
{
	printk(KERN_INFO "%s: kernel thread running.... \n", __FUNCTION__);

	allow_signal(SIGKILL);
	do {
		if (signal_pending(current) != 0)
			break;
		msleep(1000);
	} while (kthread_should_stop() != 1);

	printk(KERN_INFO "%s: kernel thread leave!! \n", __FUNCTION__);

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
