
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build123018
 *
 * Date: 2018 / 12 / 30
 *
 * Description: 
 * 1. 這是一個很簡單的Kernel Thread範例！！
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("kernel thread sample. ");
MODULE_VERSION("1.0.0.build123018");

static struct task_struct *kmain_task = (struct task_struct *)NULL;
static wait_queue_head_t wait;

static int devone_thread(void *num)
{
	printk(KERN_ALERT "%s called. \n", __FUNCTION__);
	
	for (;;) {
		// 開始執行kthread之後，睡覺3秒鐘之後起來。
		sleep_on_timeout(&wait, 3 * HZ);
		// 在kthread裡面離開要用kthread_should_stop()函式。
		if (kthread_should_stop())
			break;
	}
	printk(KERN_ALERT "%s leaved. \n", __FUNCTION__);

	return 0;
}

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install. \n");

	init_waitqueue_head(&wait);
	kmain_task = kthread_create(devone_thread, NULL, "devone_kthread");
	// kthread_create()只是先創建一個Kernel Thread. 
	if (IS_ERR(kmain_task) != 0)
		return PTR_ERR(kmain_task);
	// wake_up_process()才是真正地啟動Thread!! 
	wake_up_process(kmain_task);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
	// 要卸載模組的時候則是使用kthread_stop()函式！
	kthread_stop(kmain_task);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
