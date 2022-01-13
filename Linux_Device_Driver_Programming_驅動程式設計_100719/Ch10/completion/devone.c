
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122918
 *
 * Date: 2018 / 12 / 29
 *
 * Description: 
 * 1. 這是一個completion (等待完成)的範例；目前為止還並不是很清楚這種功能該怎麼用。
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("completion (等待完成) sample. ");
MODULE_VERSION("1.0.0.build122918");

static wait_queue_head_t wait;
static struct completion comp;
static pid_t thr_pid;

static int devone_thread(void *num)
{
	printk(KERN_ALERT "%s called. \n", __FUNCTION__);
	daemonize("devone_thread");
	allow_signal(SIGTERM);
	for (;;) {
		sleep_on_timeout(&wait, 3 * HZ);	// 每3秒鐘就被喚醒一次，
		if (signal_pending(current) != 0)	// 假如有收到任何的Signal (訊號)，就跳離這個迴圈。
			break;
	}
	printk(KERN_ALERT "%s leaved. \n", __FUNCTION__);
	complete_and_exit(&comp, 0);		// 結束一個completion

	return 0;
}

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install. \n");

	init_completion(&comp);
	init_waitqueue_head(&wait);
	// 建立一個Kernel Thread
	thr_pid = kernel_thread(devone_thread, NULL, CLONE_FS | CLONE_FILES);
	if (thr_pid < 0)
		return -EINVAL;

	printk(KERN_ALERT "kernel_thread: %d PID. \n", thr_pid);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
//	kill_proc(thr_pid, SIGTERM, 1);
	kill_pid(thr_pid, SIGTERM, 1);
	wait_for_completion(&comp);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
