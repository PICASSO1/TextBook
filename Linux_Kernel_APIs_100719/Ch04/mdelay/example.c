
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
 * 1. #define mdelay(n) (\
 *           (__builtin_constant_p(n) && (n)<=MAX_UDELAY_MS) ? udelay((n)*1000) : \
 *           ({unsigned long __ms=(n); while (__ms--) udelay(1000);}))
 *     #endif
 * 
 * 2. #define udelay(n) __udelay(n)
 *     extern void __udelay(unsigned long usecs);
 * 
 * 3. static inline void ndelay(unsigned long x) { udelay(DIV_ROUND_UP(x, 1000)); }
 * 4. 這3支函式只能用在Interrupt Context；
 *     第1個的單位為毫秒 (Milli Second, 10 ^ -3 = 0.001)；
 *     第2個的單位為微秒 (Micro Second, 10 ^ -6 = 0.000001)；
 *     第3個的單位為奈秒 (Nano Second, 10 ^ -9 = 0.000000001)。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/jiffies.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("m/u/ndelay() function sample. ");
MODULE_VERSION("1.0.0.build012119");

#define	DRIVER_NAME	"example"

static int hello_init(void)
{
	// 因為jiffies的單位是千分之一秒 (0.001秒)，所以：
	printk(KERN_INFO "%s driver installed (before mdelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	mdelay(1000);
	printk(KERN_INFO "%s driver installed (after mdelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	// 使用mdelay(1000)之後，前後差值應為(1000 +/- 2)左右，因為執行指令也需要時間。

	printk(KERN_INFO "%s driver installed (before udelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	udelay(1000);
	printk(KERN_INFO "%s driver installed (after udelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	// 使用udelay(1000)之後，前後差值應為(1 +/- 2)左右，所以前後的差值效果並不顯著。

	printk(KERN_INFO "%s driver installed (before ndelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	ndelay(1000);
	printk(KERN_INFO "%s driver installed (after ndelay(1000), jiffies: %ld). \n", DRIVER_NAME, jiffies);
	// 使用ndelay(1000)之後，已經看不出差異了.... 
	
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
