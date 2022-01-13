
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
 * 1. 這一支程序是從rwlock_init()一系列的函式修改而來，把原本的read_lock(), read_unlock(), write_lock()和write_unlock()置換成read_lock_irq(), 
 *     read_unlock_irq(), write_lock_irq()和write_unlock_irq()；其餘的功能都不變！
 * 
 * 2. 相關巨集定義如下 (linux/rwlock.h)：
 *     #define read_lock_irq(lock)         _raw_read_lock_irq(lock)
 *     #define write_lock_irq(lock)        _raw_write_lock_irq(lock)
 *     #define read_unlock_irq(lock)     _raw_read_unlock_irq(lock)
 *     #define write_unlock_irq(lock)    _raw_write_unlock_irq(lock)
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
MODULE_DESCRIPTION("(read/write)_(lock/unlock)_irq() series function sample. ");
MODULE_VERSION("1.0.0.build021819");

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

	read_lock_irq(&pArg->lock);
	val = pArg->val;
	read_unlock_irq(&pArg->lock);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s:  pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static void example_timeout_write(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_write);
	int ret = -1;

	write_lock_irq(&pArg->lock);
	pArg->val++;
	write_unlock_irq(&pArg->lock);

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
