
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
 * 1. 比較一下三種建立kthred (Kernel Thread)的方式；每乙種建立kthread的方式都有相關必須搭配的函式：
 * 2. a). kthread_create(), wake_up_process(), kthread_should_stop()和kthread_stop()。
 *     b). kthread_run(), kthread_should_stop()和kthread_stop()。
 *     c). kernel_thread(), daemonize(), find_vpid()和kill_pid()。
 * 
 * 3. 使用kthread_create()一系列的函式，是屬於建立kthread較正規的作法；而kthread_run()是一個巨集，裡面直接包含了kthread_create()和wake_up_process()。
 * 
 * 4. a) 而kernel_thread()函式，它的回傳值是建立kthread的PID (pid_t)；
 *     b) 用kernel_thread()函式創建出來的kthread function一定要加上daemonize()函式，它的意思是代表「在背景執行」，相當於在User Space下的
 *         command '&'，例如：./a.out &
 *     c) 在刪除kthread的時候，要用kill_pid(struct pid *pid, int sig, int priv); 函式，注意！kill_pid()的第一個參數是"struct pid *pid"，所以不可以使用
 *         kernel_thread()函式的回傳值，因為它是pid_t的型態。
 *     d) 所以必須要用struct pid *find_vpid(int nr); 做轉換。
 * 
 * 5. 這一支模組程序執行起來沒什麼問題，挺正常的；但是在卸載模組的時候會出現Kernel Oops的告警訊息，還不清楚原因是什麼.... 
 * 
 * 6. 假如在卸載模組前，kthread function就已經執行完畢，再執行kill_pid()也會有Kernel Oops的告警訊息，因為PID已經不存在了！看起來，kernel_thread()
 *     一系列的函式似乎並沒有那麼好用。
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
MODULE_DESCRIPTION("kernel_thread() function sample. ");
MODULE_VERSION("1.0.0.build011919");

#define	DRIVER_NAME	"example"

static pid_t kthread_pid = (pid_t)0;

static int kthread_function(void *num)
{
	int i = 0;

	printk(KERN_INFO "%s: kernel thread running.... \n", __FUNCTION__);

	daemonize("kthread_function");
	do {
		ssleep(1);
	} while (1);

	printk(KERN_INFO "%s: kernel thread leave!! \n", __FUNCTION__);

	return 0;
}

static int hello_init(void)
{
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	kthread_pid = kernel_thread(kthread_function, NULL, CLONE_FS | CLONE_FILES | CLONE_SIGHAND);
	if (kthread_pid < 0)
		return -EINVAL;
	printk(KERN_INFO "%s driver installed (kthread_pid = %d). \n", DRIVER_NAME, kthread_pid);

	return 0;
}

static void hello_exit(void)
{
	struct pid *kthread_vpid = find_vpid((int)kthread_pid);

	kill_pid(kthread_vpid, SIGTERM, 1);
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
