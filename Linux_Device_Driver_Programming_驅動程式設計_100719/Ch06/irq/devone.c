
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121518
 *
 * Date: 2018 / 12 / 15
 *
 * Description: 
 * 1. 這一個範例也很簡單，呈現Interrupt Entry Point的寫法：request_irq(); 和free_irq(); 。
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");

#define	IRQ_NUM		16

static irqreturn_t devone_interrupt(int irq, void *dev_id)
{
	printk(KERN_ALERT "IRQ: %d; dev_id: 0x%p (%s) \n", irq, dev_id, __FUNCTION__);

	return IRQ_NONE;
}

static int hello_init(void)
{
	printk(KERN_ALERT "Driver install. But I have an IRQ. \n");

	if (request_irq(IRQ_NUM, devone_interrupt, IRQF_SHARED, "devone_interrupt", (void *)devone_interrupt) != 0) {
		
	}

	return 0;
}

static void hello_exit(void)
{
	free_irq(IRQ_NUM, (void *)devone_interrupt);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
