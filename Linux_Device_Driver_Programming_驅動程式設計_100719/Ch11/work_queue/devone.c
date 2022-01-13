
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
MODULE_DESCRIPTION("Work Queue sample. ");
MODULE_VERSION("1.0.0.build010219");

const int IRQ_NUM = 17;
void *irq_dev_id = (void *)&IRQ_NUM;
struct work_struct workq;

void devone_workqueue(struct work_struct *work)
{	// 這一行就更奇怪了！加上current->pid，make就不會過？暫時先不理會.... @@
//	printk(KERN_ALERT "%s called: %ld, %ld, %ld; PID: %d \n", __FUNCTION__, in_irq(), in_softirq(), in_interrupt(), current->pid);
	printk(KERN_INFO "%s called: %ld, %ld, %ld. \n", __FUNCTION__, in_irq(), in_softirq(), in_interrupt());
	// 課本上有msleep()這一行；問題是Work Queue是運作在Process Context上，一使用就睡著了，最後就只能重開機。把這一行註解掉依然可以運作。
//	msleep(3000);

	return;
}

irqreturn_t devone_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0) {
		printk(KERN_INFO "%s: irq %d dev_instance 0x%p (%ld, %ld, %ld). \n", __FUNCTION__, irq, dev_instance, in_irq(), in_softirq(), in_interrupt());
		schedule_work(&workq);
	}

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = 0;

	printk(KERN_INFO "devone driver install. \n");
	INIT_WORK(&workq, devone_workqueue);
	ret = request_irq(IRQ_NUM, devone_isr, IRQF_SHARED, "devone", irq_dev_id);
	if (ret != 0) {
		printk(KERN_INFO "request_irq() failed (%d)!! \n", ret);
		goto out;
	}
out:
	return ret;
}

static void hello_exit(void)
{
	printk(KERN_INFO "devone driver uninstall. \n");
	flush_scheduled_work();
	free_irq(IRQ_NUM, irq_dev_id);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
