
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012919
 *
 * Date: 2019 / 01 / 29
 *
 * Description: 
 * 1. 這一個程序的用意是在呈現down_interruptible(); 函式的用法。
 *     down(); Semaphore Probern (Probern, test, descrease, -1).
 *     up(); Semaphore Verhogen (Verhogen, increase, +1).
 * 
 * 2. 在<linux/semaphore.h>中可以得知：
 *     #define init_MUTEX(sem)			sema_init(sem, 1)
 *     #define init_MUTEX_LOCKED(sem)	sema_init(sem, 0)
 *     用init_MUTEX()初始化一個struct semaphore的時候，他的值是設定成"1"；而
 *     用init_MUTEX_LOCKED()初始化的時候則是"0"。即一開始先執行了一次down()。
 * 
 * 3. 這一個範例一開始用sema_init()函式將值設定成"5"，即連續up()了5次；所以第一次執行down_interruptible()函式時，會執行成功函式回傳0，值也會
 *     減1。
 * 
 * 4. 接著用init_MUTEX_LOCKED()巨集再初始化一次struct semaphore，此時已經先down()過1次了，
 * 
 * 5. 第2次執行down_interruptible()函式時，程式發現之前已經down()過1次了，於是就不會有動作，等待Signal (信號)來中斷這一次的鎖定。所以值也不
 *     會減1。
 * 
 * 6. 這裡Signalg是指任何的信號，所以不需要使用allow_signal()來進行設定；但是當輸入為SIGUSR1時會有Kernel Oops的問題，目前還並不清楚原因。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/kthread.h>
#include <asm/current.h>
#include <linux/semaphore.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("sema_init(), init_MUTEX_LOCKED() and down_interruptible() feature sample. ");
MODULE_VERSION("1.0.0.build012919");

#define	DRIVER_NAME	"example"

static struct semaphore sem;

static int hello_init(void)
{
	int ret = 0;

	sema_init(&sem, 5);

	printk(KERN_INFO "%s: sema_init() sem.lock.rlock.raw_lock.slock: %d \n", __FUNCTION__, sem.lock.rlock.raw_lock.slock);
	printk(KERN_INFO "%s: sema_init() sem.count: %u \n", __FUNCTION__, sem.count);
	printk(KERN_INFO "%s: sema_init() sem.wait_list.next: 0x%p \n", __FUNCTION__, sem.wait_list.next);
	printk(KERN_INFO "%s: sema_init() sem.wait_list.prev: 0x%08X \n", __FUNCTION__, (unsigned int)sem.wait_list.prev);

	ret = down_interruptible(&sem);

	printk(KERN_INFO "\n1st down_interruptible(&sem) = %d \n", ret);
	printk(KERN_INFO "%s: 1st down_interruptible() sem.lock.rlock.raw_lock.slock: %d \n", __FUNCTION__, sem.lock.rlock.raw_lock.slock);
	printk(KERN_INFO "%s: 1st down_interruptible() sem.count: %u \n", __FUNCTION__, sem.count);
	printk(KERN_INFO "%s: 1st down_interruptible() sem.wait_list.next: 0x%p \n", __FUNCTION__, sem.wait_list.next);
	printk(KERN_INFO "%s: 1st down_interruptible() sem.wait_list.prev: 0x%08X \n", __FUNCTION__, (unsigned int)sem.wait_list.prev);

	init_MUTEX_LOCKED(&sem);

	printk(KERN_INFO "\ninit_MUTEX_LOCKED(&sem): \n");
	printk(KERN_INFO "%s: init_MUTEX_LOCKED() sem.lock.rlock.raw_lock.slock: %d \n", __FUNCTION__, sem.lock.rlock.raw_lock.slock);
	printk(KERN_INFO "%s: init_MUTEX_LOCKED() sem.count: %u \n", __FUNCTION__, sem.count);
	printk(KERN_INFO "%s: init_MUTEX_LOCKED() sem.wait_list.next: 0x%p \n", __FUNCTION__, sem.wait_list.next);
	printk(KERN_INFO "%s: init_MUTEX_LOCKED() sem.wait_list.prev: 0x%08X \n", __FUNCTION__, (unsigned int)sem.wait_list.prev);

	ret = down_interruptible(&sem);
	
	printk(KERN_INFO "\n2nd down_interruptible(&sem) = %d \n", ret);
	printk(KERN_INFO "%s: 2nd down_interruptible() sem.lock.rlock.raw_lock.slock: %d \n", __FUNCTION__, sem.lock.rlock.raw_lock.slock);
	printk(KERN_INFO "%s: 2nd down_interruptible() sem.count: %u \n", __FUNCTION__, sem.count);
	printk(KERN_INFO "%s: 2nd down_interruptible() sem.wait_list.next: 0x%p \n", __FUNCTION__, sem.wait_list.next);
	printk(KERN_INFO "%s: 2nd down_interruptible() sem.wait_list.prev: 0x%08X \n", __FUNCTION__, (unsigned int)sem.wait_list.prev);

	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
