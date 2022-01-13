
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121618
 *
 * Date: 2018 / 12 / 16
 *
 * Description: 
 * 1. 首先，這一支程序完全無法make，因為這一支程序展現了Memery mapped I/O的寫法；而Bus Address必須要是實體裝置的Address。
 * 2. "千萬不要make.... "
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/ioport.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");

static char *reg = (char *)NULL;
static struct resource *res = (struct resource *)NULL;

static int hello_init(void)
{
	printk(KERN_ALERT "Driver install. But I have an Memery mapped I/O. \n");

/*	struct resource *request_mem_region(resource_size_t start, resource_size_t n, const char *name);
	NOTE: 
	1. 在使用Memery mapped I/O 的時候，要先預先保留位址的範圍就必需先使用request_mem_region(); 
	2. 第1個參數resource_size_t start: 是實體的Bus Address；
	3. 第2個參數resource_size_t n: 是Byte單位的範圍大小；
	4. 第3個參數const char *name: 是"名稱"，可以在/proc/iomem找到。
*/	reg = ioremap_nocache(0xFF6F0800, 8);
/*	NOTE: 
	1. 當Driver要讀寫MMIO的時候，必須要透過ioremap_nocache(); 這一類的函式來讀取；
	2. 但每一個平台都不太一樣，課本上的範例是用ioremap_nocache(); 但我在Fedora Core 13上並沒找到這一個函式，反而是找到: 
	    void __iomem *devm_ioremap_nocache(struct device *dev, resource_size_t offset,unsigned long size); 
	3. 所以，還是要看每一個平臺是提供哪一種類型的函式。
*/	if (reg != (char *)NULL)
		printk(KERN_ALERT "0x%X \n", reg);

	return 0;
}

static void hello_exit(void)
{
	iounmap(reg);
	// 相對應於ioremap_nocache(); 
//	void release_mem_region(resource_size_t start, resource_size_t n);
	// 相對應於request_mem_region(); 
	
	return;
}

module_init(hello_init);
module_exit(hello_exit);
