
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122218
 *
 * Date: 2018 / 12 / 22
 *
 * Description: 
 * 1. 這是一支有問題的程序：kmalloc()函式的第2個參數的用法：GFP_ATOMIC, GFP_KERNEL和GFP_DMA。
 * 2. GFP_ATOMIC: 只能用在Interrupt Context (Interrupt and Timer Entry Point)，取用記憶體的過程中不可以sleep()。
 * 3. GFP_KERNEL: 能用在Process Context (Insert, rmmove module and system call Entry Point)，取用記憶體的過程中可以sleep()。
 * 4. GFP_DMA: 取得ISA等等傳統裝置使用的DMA暫存區。
 * 5. 所以，這一個範例的問題在於Timer Entry Point中使用了GFP_KERNEL (應為GFP_ATOMIC)；所以會出現Kernel Alarm Message!!
 *
 * 6. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION(" ");
MODULE_VERSION("1.0.0.build122218");

#define	TIMEOUT_VALUE	(5 * HZ)

static struct timer_list tickfn;

static void devone_timeout(unsigned long arg)
{
	struct timer_list *ptr = (struct timer_list *)arg;
	void *memptr = (void *)NULL;

	printk(KERN_ALERT "ptr: 0x%p; memptr: 0x%p (%s) \n", ptr, memptr, __FUNCTION__);
	// Bug!! Correct: GFP_ATOMIC
	memptr = (void *)kmalloc(1024 * 1024, GFP_KERNEL);
	if (ptr != (struct timer_list *)NULL) {
		printk(KERN_ALERT "ptr: 0x%p; memptr: 0x%p (%s) \n", ptr, memptr, __FUNCTION__);
		kfree((void *)memptr);
	}

	return;
}

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install (&tickfn: 0x%p). \n", &tickfn);
	init_timer(&tickfn);
	tickfn.function = devone_timeout;
	tickfn.data = (unsigned long)&tickfn;
	tickfn.expires = jiffies + TIMEOUT_VALUE;
	add_timer(&tickfn);

	return 0;
}

static void hello_exit(void)
{
	int ret = del_timer_sync(&tickfn);

	printk(KERN_ALERT "devone driver uninstall (ret: %d). \n", ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
