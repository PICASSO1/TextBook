
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build021619
 *
 * Date: 2019 / 02 / 16
 *
 * Description: 
 * 1. 這一個範例是從"rwlock_init"改寫而來，在read_lock()和write_lock()之前先用"read_trylock()"和"write_trylock()"判斷是否能夠成功的取得讀寫鎖。
 * 
 * 2. #define read_trylock(lock)	__cond_lock(lock, _raw_read_trylock(lock))
 *     #define write_trylock(lock)	__cond_lock(lock, _raw_write_trylock(lock))
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
MODULE_DESCRIPTION("read_trylock() and write_trylock() function sample. ");
MODULE_VERSION("1.0.0.build021619");

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

	if (read_trylock(&pArg->lock) == 0) {	// 假如取得讀者鎖失敗，
		write_unlock(&pArg->lock);			// 先釋放寫者鎖，
		read_lock(&pArg->lock);			// 鎖上讀者鎖，
		val = pArg->val;					// 取值.... 
		read_unlock(&pArg->lock);			// 取完值釋放讀者鎖，
		write_lock(&pArg->lock);			// 再重鎖上寫者鎖。
	}
	else {								// 假如取得讀者鎖成功，就直接取值然後釋放讀者鎖！
		val = pArg->val;
		read_unlock(&pArg->lock);
	}

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s:  pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static void example_timeout_write(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_write);
	int ret = -1;

	if (write_trylock(&pArg->lock) == 0) {	// 假如取得寫者鎖失敗，
		read_unlock(&pArg->lock);			// 先釋放讀者鎖，
		write_lock(&pArg->lock);			// 鎖上寫者鎖，
		pArg->val++;					// 把值加1
		write_unlock(&pArg->lock);			// 加完值釋放寫者鎖，
		read_lock(&pArg->lock);			// 再重鎖上讀者鎖。
	}
	else {								// 假如取得寫者鎖成功，就直接加值然後釋放寫者鎖！
		pArg->val++;
		write_unlock(&pArg->lock);
	}

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
