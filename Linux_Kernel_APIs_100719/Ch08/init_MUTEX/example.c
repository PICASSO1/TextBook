
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
 * 1. 這一個範例是在練習Semaphore的用法。在Linux Kernel Space裡面，如果遇到Critical Session (臨界區間)Race Condition (Racing, 競走現象)的
 *     狀況，就必須先用Semaphore (號誌)來進行鎖定，當操作完畢之後再進行解鎖。
 * 
 * 2. Semaphore只能用在Process Context。
 * 
 * 3. 因為Semaphore只能用在Process Context，所以在Module Entry Point：
 *     a) 先將初始值設為0，然後用init_MUTEX()巨集初始化Semaphore結構；
 *     b) 建立2個kthread，一個用來將值加2 (adder_kthrFunC)。
 *     c) 而另一個 (revert_kthrFunC)則是用來監控值是否超過20；如果值超過20的時候是偶數，就把它設為1，反之設為0。
 *     d) 為了避免在revert_kthrFunC歸位的時候，adder_kthrFunC還會持續地往上加2，所以在歸位的時候用down()函式對Semaphoe進行鎖定，完畢之後
 *         用up()函式解鎖。
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
MODULE_DESCRIPTION("init_MUTEX(), down() and up() feature sample. ");
MODULE_VERSION("1.0.0.build012919");

#define	DRIVER_NAME	"example"

static struct task_struct *adder_kthr = (struct task_struct *)NULL;
static struct task_struct *revert_kthr = (struct task_struct *)NULL;

struct example_data {
	unsigned int val;
	struct semaphore sem;
} *globle_data = (struct example_data *)NULL;

static int adder_kthrFunC(void *num)
{
	struct example_data *adder_Data = (struct example_data *)num;

	while (1) {
		printk(KERN_INFO "%s: adder_Data->val = %d \n", __FUNCTION__, adder_Data->val);
		adder_Data->val += 2;
		msleep(1000);
		if (kthread_should_stop() == 1)
			break;
	}
	
	return 0;
}

static int revert_kthrFunC(void *num)
{
	struct example_data *revert_Data = (struct example_data *)num;

	while (1) {
		if (revert_Data->val >= 20) {
			down(&revert_Data->sem);
			revert_Data->val = ((revert_Data->val % 2) == 0)? 1U: 0U;
			up(&revert_Data->sem);
		}
		ssleep(1);

		if (kthread_should_stop())
			break;
	}
	
	return 0;
}

static int hello_init(void)
{
	struct example_data *module_Data = globle_data;

	module_Data = (struct example_data *)kzalloc(sizeof(struct example_data), GFP_KERNEL);
	if (module_Data == (struct example_data *)NULL)
		return -ENOMEM;

	module_Data->val = 0U;
	init_MUTEX(&module_Data->sem);

	adder_kthr = kthread_create(adder_kthrFunC, (void *)module_Data, "adder_kthr");
	if (IS_ERR(adder_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (adder_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(adder_kthr);
	}
	wake_up_process(adder_kthr);

	revert_kthr = kthread_run(revert_kthrFunC, (void *)module_Data, "revert_kthr");
	if (IS_ERR(revert_kthr) != 0) {
		printk(KERN_ERR "%s driver kthread (revert_kthr) failed!! \n", DRIVER_NAME);
		return PTR_ERR(revert_kthr);
	}

	printk(KERN_INFO "%s driver installed (adder_kthr: %d; revert_kthr: %d). \n", \
		DRIVER_NAME, (int)adder_kthr->pid, (int)revert_kthr->pid);

	return 0;
}

static void hello_exit(void)
{
	int ret_revert = -1, ret_adder = -1;
	
	if (IS_ERR(revert_kthr) == 0)
		ret_revert = kthread_stop(revert_kthr);

	if (IS_ERR(adder_kthr) == 0)
		ret_adder = kthread_stop(adder_kthr);
	
	if (globle_data != (struct example_data *)NULL)
		kfree((void *)globle_data);

	printk(KERN_INFO "%s driver uninstalled (revert_kthr: %d; adder_kthr: %d). \n", \
		DRIVER_NAME, ret_revert, ret_adder);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
