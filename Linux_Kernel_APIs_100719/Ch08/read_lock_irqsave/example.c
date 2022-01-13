
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
 * 1. 這一支程序是從spin_lock_irq()一系列的函式修改而來，把原本的spin_lock_irq(), spin_unlock_irq(), spin_lock_irqsave()和spin_unlock_irqrestore()
 *     置換成read_lock_irqsave(), read_unlock_irqrestore(), write_lock_irqsave()和write_unlock_irqrestore()；其餘的功能都不變！相關巨集定義如下
 *      (linux/rwlock.h)：
 *
 * 2. #define read_lock_irqsave(lock, flags)    \
 *     do {                                                         \
 *         typecheck(unsigned long, flags);         \
 *         flags = _raw_read_lock_irqsave(lock); \
 *     } while (0)
 * 
 * 3. #define write_lock_irqsave(lock, flags)    \
 *     do {                                                          \
 *         typecheck(unsigned long, flags);          \
 *         flags = _raw_write_lock_irqsave(lock); \
 *     } while (0)
 * 
 * 4. #define read_unlock_irqrestore(lock, flags) \
 *     do {                                                              \
 *         typecheck(unsigned long, flags);              \
 *         _raw_read_unlock_irqrestore(lock, flags); \
 *     } while (0)
 * 
 * 5. #define write_unlock_irqrestore(lock, flags) \
 *     do {                                                               \
 *         typecheck(unsigned long, flags);               \
 *         _raw_write_unlock_irqrestore(lock, flags); \
 *     } while (0)
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
#include <linux/jiffies.h>
#include <linux/spinlock.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("(read/write)_(lock/unlock)_(irqsave/irqrestore)() function samples. ");
MODULE_VERSION("1.0.0.build021819");

#define	TIMEOUT_VALUE	(1 * HZ)

static struct example_data {
	unsigned int val;
	rwlock_t lock;
	struct timer_list timer_read;
} *global_data = (struct example_data *)NULL;

static struct task_struct *kthr_write = (struct task_struct *)NULL;

unsigned long flags = 0UL;

static void example_timeout_read(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_read);
	int ret = -1;
	unsigned int  val = -1;

	read_lock_irqsave(&pArg->lock, flags);
	val = pArg->val;
	read_unlock_irqrestore(&pArg->lock, flags);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s: pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static int example_kthrFunC_write(void *num)
{
	struct example_data *kthrFunC_Data = (struct example_data *)num;

	while (1) {
		write_lock_irqsave(&kthrFunC_Data->lock, flags);
		kthrFunC_Data->val++;
		write_unlock_irqrestore(&kthrFunC_Data->lock, flags);

		printk(KERN_INFO "%s: kthrFunC_Data->val = %d \n", __FUNCTION__, kthrFunC_Data->val);
		msleep(1000);
		if (kthread_should_stop() == 1)
			break;
	}
	
	return 0;
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

	kthr_write = kthread_run(example_kthrFunC_write, (void *)local_data, "example_kthrFunC_write");
	if (IS_ERR(example_kthrFunC_write) != 0) {
		printk(KERN_ERR "example driver kthread (example_kthrFunC_write) failed!! \n");
		return PTR_ERR(example_kthrFunC_write);
	}

	printk(KERN_INFO "example driver (%s) installed (jiffies: %lu; kthr_write: %d). \n", __FUNCTION__, jiffies, (int)kthr_write->pid);

	return 0;
}

static void hello_exit(void)
{
	int ret = -1, ret_adder = -1;

	if (IS_ERR(kthr_write) == 0)
		ret_adder = kthread_stop(kthr_write);

	ret = del_timer_sync(&global_data->timer_read);

	if (global_data != (struct example_data *)NULL)
		kfree((void *)global_data);

	printk(KERN_INFO "example driver (%s) uninstalled (ret_adder = %d; ret = %d). \n", __FUNCTION__, ret_adder, ret);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
