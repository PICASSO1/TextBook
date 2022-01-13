
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012219
 *
 * Date: 2019 / 01 / 22
 *
 * Description: 
 * 1. 因為接收到來自硬體的中斷訊號之後，可能還要處理許多事情，但是為了讓程式能夠馬上返回接收下一次的中斷，那些「其它的事情處理機制」統稱叫做
 *     「Bottom Half」。在linux-2.4.x有Task Queue (在linux-2.6.x已經淘汰了)，取而代之的是tasklet和Work Queue。
 * 2. 兩者的差異在於tasklet運作在Interrupt Context；而Work Queue則是運作在Process Context。函式原型如下：
 * 3. void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data); 
 * 4. static inline void tasklet_schedule(struct tasklet_struct *t)
 *     {
 *         if (!test_and_set_bit(TASKLET_STATE_SCHED, &t->state))
 *             __tasklet_schedule(t);
 *     }
 * 5. void tasklet_kill(struct tasklet_struct *t); 
 * 6. 在這個範例之中，還有3個巨集：
 *     a) in_irq(): 如果CPU正在服務硬體中斷，就會回傳TRUE。
 *     b) in_softirq(): 如果CPU正在服務軟體中斷，就會回傳TRUE。
 *     c) in_interrupt(): 如果CPU正在服務硬體中斷或是軟體中斷，或者先佔功能 (Preemption)是關閉的，也會回傳TRUE。
 * 
 * 7. Linux Kernel的中斷機制挺複雜的，並沒有像範例中那樣幾個函式就能夠解決。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("tasklet feature sample. ");
MODULE_VERSION("1.0.0.build012219");

const int IRQ_NUM = 10;
void *irq_dev_id = (void *)&IRQ_NUM;
struct tasklet_struct tasklet;

#define	DRIVER_NAME	"example"

void example_tasklet(unsigned long data)
{
	printk(KERN_INFO "%s: in_irq() = %ld; in_softirq() = %ld; in_interrupt() = %ld; data = %ld \n", \
		__FUNCTION__, in_irq(), in_softirq(), in_interrupt(), data);

	return;
}

irqreturn_t example_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0) {
		printk(KERN_INFO "%s: irq %d; dev_instance 0x%p. \n", __FUNCTION__, irq, dev_instance);
		tasklet_schedule(&tasklet);
	}

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = -1;

	tasklet_init(&tasklet, example_tasklet, 6);
	ret = request_irq(IRQ_NUM, example_isr, IRQF_SHARED, "example", irq_dev_id);
	if (ret != 0) {
		printk(KERN_INFO "request_irq(%d) failed!! \n", ret);
		tasklet_kill(&tasklet);
		return ret;
	}
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	free_irq(IRQ_NUM, irq_dev_id);
	tasklet_kill(&tasklet);
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
