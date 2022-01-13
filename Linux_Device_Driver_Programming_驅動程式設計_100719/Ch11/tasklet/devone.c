
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build010219
 *
 * Date: 2019 / 01 / 02
 *
 * Description: 
 * 1. 因為接收到來自硬體的中斷訊號之後，可能還要處理許多事情，但是為了讓程式能夠馬上返回接收下一次的中斷，那些「其它的事情處理機制」就是tasklet和Work Queue。
 * 2. 兩者的差異在於tasklet運作在Interrupt Context；而Work Queue則是運作在Process Context。
 *
 * 3. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("tasklet sample. ");
MODULE_VERSION("1.0.0.build010219");

const int IRQ_NUM = 17;
void *irq_dev_id = (void *)&IRQ_NUM;
struct tasklet_struct tasklet;

void devone_tasklet(unsigned long data)
{
	printk(KERN_INFO "%s called: %ld, %ld, %ld \n", __FUNCTION__, in_irq(), in_softirq(), in_interrupt());

	return;
}

irqreturn_t devone_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0) {
		printk(KERN_INFO "%s: irq %d dev_instance 0x%p (%ld, %ld, %ld). \n", __FUNCTION__, irq, dev_instance, in_irq(), in_softirq(), in_interrupt());
		tasklet_schedule(&tasklet);
	}

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = 0;

	printk(KERN_ALERT "devone driver install. \n");
	tasklet_init(&tasklet, devone_tasklet, 0);
	ret = request_irq(IRQ_NUM, devone_isr, IRQF_SHARED, "devone", irq_dev_id);
	if (ret != 0) {
		printk(KERN_INFO "request_irq() failed!! \n", ret);
		tasklet_kill(&tasklet);
		goto out;
	}
out:
	return ret;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
	tasklet_kill(&tasklet);
	free_irq(IRQ_NUM, irq_dev_id);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
