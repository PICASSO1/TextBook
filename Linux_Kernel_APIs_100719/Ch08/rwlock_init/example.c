
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build021519
 *
 * Date: 2019 / 02 / 15
 *
 * Description: 
 * 1. 這一個範例程序是呈現rwlock_init(), read_lock(), read_unlock(), write_lock()和write_unlock()的用法；相關的巨集和函式定義在<linux/rwlock.h>
 * 2. # define rwlock_init(lock)     do { *(lock) = __RW_LOCK_UNLOCKED(lock); } while (0)
 *     #define write_lock(lock)       _raw_write_lock(lock)
 *     #define read_lock(lock)        _raw_read_lock(lock)
 *     #define read_unlock(lock)    _raw_read_unlock(lock)
 *     #define write_unlock(lock)   _raw_write_unlock(lock)
 * 
 * 3. 程序一開始的時候，就先建立2個Internal Timer Entry Point，一個是用來Read (讀取)，另一個則是Write (寫入)；它是屬於Interrupt Context所以
 *     在分配記憶體位置的時候要使用"GFP_ATOMIC"。
 * 
 * 4. 讀寫鎖 (R/W Lock)是一種特殊的自旋鎖 (Spin Lock, Busy-Loop)。無論是自旋鎖或是讀寫鎖，它是應用在Interrupt Context的Race Condition (Rac
 *     ing, 競走現象)時的Critical Session (臨界區間)。為了刻意製造出Race Condition的狀況，所以TimeOut時間均設定成1秒。
 * 
 * 5. 在讀取的Timer Entry Point (example_timeout_read())，在讀值的時候，前後加上read_lock()和read_unlock()巨集；而
 *     在寫入的Timer Entry Point (example_timeout_write())，在寫值的時候，前後加上write_lock()和write_unlock()巨集。範例非常簡單！
 * 
 * 6. 讀寫鎖實際是一種特殊的自旋鎖，它把對共享資源的訪問者劃分成讀者和寫者，讀者只對共享資源進行讀訪問，寫者則需對共享資源進行寫操作。這種鎖相對
 *     於自旋鎖而言，能提高併發性，因為在多處理器的系統中，他允許同時有多個讀者來訪問共享資源，最大可能的讀者數為邏輯CPU數。寫者是排它性的，一個
 *     讀寫鎖同時只能有一個寫者或是多個讀者 (與CPU數量相關)，但不能同時既有讀者又有寫者。在讀寫鎖的保持期間也是搶佔 (Preemptive)失效的。
 * 
 * 7. 如果讀寫鎖當前沒有讀者，也沒有寫者。那麼寫者可以立刻獲得讀寫鎖，否則它必須自旋 (Busy-Loop)在那裡，直到沒有任何讀者或寫者。如果讀寫鎖沒有寫
 *   者，那麼讀者可以立即獲得該讀寫鎖，否則讀者必須自旋在那裡，直到寫者釋放該讀寫鎖。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/kthread.h>
#include <asm/current.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/spinlock.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("rwlock_init() series function sample. ");
MODULE_VERSION("1.0.0.build021519");

#define	TIMEOUT_VALUE	(1 * HZ)

static struct example_data {
	unsigned int val;
	rwlock_t lock;
	struct timer_list timer_read;
	struct timer_list timer_write;
} *global_data = (struct example_data *)NULL;

static void example_timeout_read(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_read);
	int ret = -1;
	unsigned int  val = -1;

	read_lock(&pArg->lock);
	val = pArg->val;
	read_unlock(&pArg->lock);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s:  pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static void example_timeout_write(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_write);
	int ret = -1;

	write_lock(&pArg->lock);
	pArg->val++;
	write_unlock(&pArg->lock);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s: pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, pArg->val);

	return;
}

static int hello_init(void)
{
	struct example_data *local_data = (struct example_data *)NULL;

	local_data = (struct example_data *)kzalloc(sizeof(struct example_data), GFP_ATOMIC);
	if (local_data == (struct example_data *)NULL)
		return -ENOMEM;

	local_data->val = 0;
	rwlock_init(&local_data->lock);
	global_data = local_data;

	init_timer(&local_data->timer_read);
	local_data->timer_read.function = example_timeout_read;
	local_data->timer_read.data = (unsigned long)local_data;
	local_data->timer_read.expires = jiffies + TIMEOUT_VALUE;
	add_timer(&local_data->timer_read);

	init_timer(&local_data->timer_write);
	local_data->timer_write.function = example_timeout_write;
	local_data->timer_write.data = (unsigned long)local_data;
	local_data->timer_write.expires = jiffies + TIMEOUT_VALUE;
	add_timer(&local_data->timer_write);

	printk(KERN_INFO "example driver (%s) installed (jiffies: %lu). \n", __FUNCTION__, jiffies);

	return 0;
}

static void hello_exit(void)
{
	int ret_write = -1, ret_read = -1;

	ret_write = del_timer_sync(&global_data->timer_write);
	
	ret_read = del_timer_sync(&global_data->timer_read);

	if (global_data != (struct example_data *)NULL)
		kfree((void *)global_data);

	printk(KERN_INFO "example driver (%s) uninstalled (ret_write = %d; ret_read = %d). \n", __FUNCTION__, ret_write, ret_read);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
