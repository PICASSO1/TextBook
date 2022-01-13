
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122218
 *
 * Date: 2018 / 12 / 22
 *
 * Description: 
 * 1. 這一支程序展現了在Kernel Space中，使用「全域變數」的一些限制：
 *     a). 全域變數會在整個驅動程式之內共享；
 *     b). 對編譯成module的驅動程式而言，其它module看不到它的全域變數；但可用EXPORT_SYMBOL()巨集對外公開；
 *     c). 對靜態連結到kernel的驅動程式而言，全域變數是整個kernel都看得到的。
 *
 * 2. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("Global Variable sample. ");
MODULE_VERSION("1.0.0.build122218");

int g_devone_counter0 __attribute__ ((unused));
const int g_devone_counter1 __attribute__ ((unused));
static int g_devone_counter2 __attribute__ ((unused));
int g_devone_counter3 __attribute__ ((unused));
EXPORT_SYMBOL(g_devone_counter3);

static int hello_init(void)
{
	printk(KERN_ALERT "devone driver install. \n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
