#include <linux/module.h>
#include <linux/init.h>

void sub(void)
{
	printk(KERN_INFO "%s: sub() called. \n", __func__);

	return;
}
