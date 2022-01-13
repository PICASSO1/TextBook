
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
 * 2. 兩者的差異在於tasklet運作在Interrupt Context；而Work Queue則是運作在Process Context。
 * 
 * 3. Linux Kernel的中斷機制挺複雜的，並沒有像範例中那樣幾個函式就能夠解決。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("Work Queue function sample. ");
MODULE_VERSION("1.0.0.build012219");

const int IRQ_NUM = 10;
void *irq_dev_id = (void *)&IRQ_NUM;
struct work_struct workq;

#define	DRIVER_NAME	"example"

void example_workqueue(struct work_struct *work)
{
	printk(KERN_INFO "%s: in_irq() = %ld; in_softirq() = %ld; in_interrupt() = %ld \n", __FUNCTION__, in_irq(), in_softirq(), in_interrupt());
//	msleep(1000);

	return;
}

irqreturn_t example_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0) {
		printk(KERN_INFO "%s: irq %d; dev_instance 0x%p. \n", __FUNCTION__, irq, dev_instance);
		schedule_work(&workq);
	}

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = -1;

	INIT_WORK(&workq, example_workqueue);
	ret = request_irq(IRQ_NUM, example_isr, IRQF_SHARED, "example", irq_dev_id);
	if (ret != 0) {
		printk(KERN_INFO "request_irq(%d) failed!! \n", ret);
		return ret;
	}
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	free_irq(IRQ_NUM, irq_dev_id);
	flush_scheduled_work();
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
