
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
 * 1. 這一個範例是Interrupt Context中的Interrupt Entry Point。它是用來接收來自硬體的中斷訊號。除了使用request_irq()和free_irq()函式之外，在Critical Session的處理上，
 *     時間也要極力縮短。
 * 2. make完這一個模組之後，在"dmesg -c"會一直持續地看到相關的訊息，因為Kernel一直在偵測是否有硬體中斷的訊號。
 *
 * 3. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("irq_request sample. ");
MODULE_VERSION("1.0.0.build010219");

const int IRQ_NUM = 17;
void *irq_dev_id = (void *)&IRQ_NUM;

irqreturn_t devone_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0)
		printk(KERN_INFO "%s: irq %d dev_instance 0x%p. \n", __FUNCTION__, irq, dev_instance);

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = -1;

	printk(KERN_ALERT "devone driver install. \n");
	ret = request_irq(IRQ_NUM, devone_isr, IRQF_SHARED, "devone", irq_dev_id);
	if (ret != 0) {
		printk(KERN_INFO "request_irq() failed!! \n", ret);
		return ret;
	}

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");
	free_irq(IRQ_NUM, irq_dev_id);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
