
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012119
 *
 * Date: 2019 / 01 / 21
 *
 * Description: 
 * 1. 這是一個簡單的Interrupt Context中Interrupt Entry Point的範例；函式的原型如下 (request_irq()和free_irq()必定成對出現)：
 * 
 * 2. static inline int __must_check request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags, const char *name, void *dev)
 *     {
 *         return request_threaded_irq(irq, handler, NULL, flags, name, dev);
 *     }
 * 
 * 3. void free_irq(unsigned int, void *dev_id);
 * 
 * 4. DEFINE_RATELIMIT_STATE(printk_ratelimit_state, 5 * HZ, 10); 
 *     int printk_ratelimit(void) 
 *     {
 *         return __ratelimit(&printk_ratelimit_state);
 *     }
 *     EXPORT_SYMBOL(printk_ratelimit);
 *     因為在Linux的Kernel Space中的偵測中斷機制速度非常、非常、非常地快 (例如判斷硬體的腳位是否有變化)，所以會產生大量的printk()訊息。
 *     printk_ratelimit()函式的用意就是「限制這些訊息的輸出數量」。如：5秒鐘以內最多只能輸出10條printk()訊息。
 *     相關的設定擋在這兒：
 *     cat -n /proc/sys/kernel/printk_ratelimit => 5
 *     cat -n /proc/sys/kernel/printk_ratelimit_burst => 10
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("irq_request simple sample. ");
MODULE_VERSION("1.0.0.build012119");

const int IRQ_NUM = 10;
void *irq_dev_id = (void *)&IRQ_NUM;

#define	DRIVER_NAME	"example"

irqreturn_t example_isr(int irq, void *dev_instance)
{
	if (printk_ratelimit() != 0)
		printk(KERN_INFO "%s: irq %d; dev_instance 0x%p. \n", __FUNCTION__, irq, dev_instance);

	return IRQ_NONE;
}

static int hello_init(void)
{
	int ret = request_irq(IRQ_NUM, example_isr, IRQF_SHARED, "example", irq_dev_id);

	if (ret != 0) {
		printk(KERN_INFO "request_irq() failed!! \n", ret);
		return ret;
	}
	printk(KERN_INFO "%s driver installed. \n", DRIVER_NAME);

	return 0;
}

static void hello_exit(void)
{
	free_irq(IRQ_NUM, irq_dev_id);	
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
