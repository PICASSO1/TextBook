
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
 * 1. 這一個範例程序是呈現spin_lock_init(), spin_lock_irq(), spin_unlock_irq(), spin_lock_irqsave()和spin_unlock_irqrestore()的用法；相關的巨集和
 *     函式定義在<linux/spinlock.h>: 
 * 2. #define spin_lock_init(_lock)                 \
 *     do {                                                       \
 *         spinlock_check(_lock);                       \
 *         raw_spin_lock_init(&(_lock)->rlock); \
 *     } while (0)
 * 3. static inline void spin_lock_irq(spinlock_t *lock)     { raw_spin_lock_irq(&lock->rlock); }
 * 4. static inline void spin_unlock_irq(spinlock_t *lock) { raw_spin_unlock_irq(&lock->rlock); }
 * 5. #define spin_lock_irqsave(lock, flags)                           \
 *     do {                                                                               \
 *         raw_spin_lock_irqsave(spinlock_check(lock), flags);  \
 *     } while (0)
 * 6. static inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags) { raw_spin_unlock_irqrestore(&lock->rlock, flags); }
 * 
 * 7. 程序一開始的時候，就先建立一個Timer Entry Point，它是屬於Interrupt Context，所以在分配記憶體位置的時候要使用"GFP_ATOMIC"。
 * 8. 這一個Timer Entry Point (example_timeout_read())的功能就是"讀取值"而已，所以在讀取的時候前後要加上spin_lock_irq()和spin_unlock_irq()；
 * 
 * 9. 程序接著再建立一個kthread (example_kthrFunC_write())，它是屬於Process Context，它的功能就是就是把值加一，所以在寫值得時候，前後要加
 *     上spin_lock_irqsave()和spin_unlock_irqrestore()。
 * 
 * 10. *_irqsave()的意思是"取得自旋鎖，並儲存上鎖之前的狀態"；*_irqrestore()則是"釋放自旋鎖，並回復上鎖之前的狀態"。
 * 
 * 11. 以這一個自己寫的範例而言，Timer Entry Point (example_timeout_read())是屬於Interrupt Context；而kthread (example_kthrFunC_write())
 *      是屬於Process Context。當兩者遇到讀寫的Critical Session時就可以使用spin_lock_init()一列的函式做相關的操作。
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
MODULE_DESCRIPTION("spin_(un)lock_irq(save/restore)() function samples. ");
MODULE_VERSION("1.0.0.build021819");

#define	TIMEOUT_VALUE	(1 * HZ)

static struct example_data {
	unsigned int val;
	spinlock_t lock;
	struct timer_list timer_read;
} *global_data = (struct example_data *)NULL;

static struct task_struct *kthr_write = (struct task_struct *)NULL;

static void example_timeout_read(unsigned long arg)
{
	struct example_data *pArg = (struct example_data *)arg;
	struct timer_list *pTimer = &(pArg->timer_read);
	int ret = -1;
	unsigned int  val = -1;

	spin_lock_irq(&pArg->lock);
	val = pArg->val;
	spin_unlock_irq(&pArg->lock);

	ret = mod_timer(pTimer, jiffies + TIMEOUT_VALUE);
	printk(KERN_INFO "%s: pTimer: 0x%p; jiffies: %lu; ret = %d; pArg->val = %u. \n", __FUNCTION__, pTimer, jiffies, ret, val);

	return;
}

static int example_kthrFunC_write(void *num)
{
	struct example_data *kthrFunC_Data = (struct example_data *)num;
	unsigned long flags = 0UL;

	while (1) {
		spin_lock_irqsave(&kthrFunC_Data->lock, flags);
		kthrFunC_Data->val++;
		spin_unlock_irqrestore(&kthrFunC_Data->lock, flags);

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
	spin_lock_init(&local_data->lock);
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
