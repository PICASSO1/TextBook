
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build021819
 *
 * Date: 2019 / 02 / 18
 *
 * Description: 
 * 1. 這一支程序是從rwlock_init()改寫而來；把原本的rwlock_t置換成spinlock_t；相關的函式定義如下 (linux/spinlock.h)：
 * 2. #define spin_lock_init(_lock)                 \
 *     do {                                                       \
 *         spinlock_check(_lock);                       \
 *         raw_spin_lock_init(&(_lock)->rlock); \
 *     } while (0)
 * 3. static inline void spin_lock(spinlock_t *lock)     { raw_spin_lock(&lock->rlock); }
 * 4. static inline void spin_unlock(spinlock_t *lock) { raw_spin_unlock(&lock->rlock); }
 * 5. static inline int spin_trylock(spinlock_t *lock)   { return raw_spin_trylock(&lock->rlock); }
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
#include <linux/delay.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("spin_lock_init() series function sample. ");
MODULE_VERSION("1.0.0.build021819");

#define	TIMEOUT_VALUE	(1 * HZ)

static struct example_data {
	unsigned int val;
	spinlock_t lock;
	struct timer_list timer_read;
	struct timer_list timer_write;
} *global_data = (struct example_data *)NULL;

static void example_timeout_read(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_read);
	int ret = -1;
	unsigned int  val = -1;

	spin_lock(&pArg->lock);
	val = pArg->val;
	spin_unlock(&pArg->lock);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s:  pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static void example_timeout_write(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_write);
	int ret = -1;

	do {		// spin_trylock()執行成功，會回傳0，等同於執行spin_lock()；若執行失敗則是回傳非0值。
		ndelay(1000);
	} while (spin_trylock(&pArg->lock) != 0); 
	pArg->val++;
	spin_unlock(&pArg->lock);

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
	spin_lock_init(&local_data->lock);
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
