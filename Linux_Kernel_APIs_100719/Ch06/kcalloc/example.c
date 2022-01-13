
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build010919
 *
 * Date: 2019 / 01 / 09
 *
 * Description: 
 * 1. 這一支程序展現了在Linux Kernel Space中，動態取得記憶體"不是很"常見的方式：kcalloc()。
 * 2. kcalloc()也是Slab Allocator實作出來的介面函式，「且能保證取得"實體記憶體"上連續的記憶體位址」。
 * 3. static inline void *kcalloc(size_t n, size_t size, gfp_t flags); kcalloc()函式是「為一個陣列分配記憶體空間」，陣列中的一個元素對應一個記憶體物
 *     件。換句話說，就是配置一個二維陣列的記憶體空間。
 *     size_t n: 陣列中的元素個數；size_t size: 指定陣列中每個元素所對應的記憶體物件大小。
 * 4. kcalloc()函式配置完記憶體空間之後，也會全部初始化為0x00。
 * 
 * 5. size_t ksize(const void *objp); ksize()函式可以計算kmalloc(), kzalloc()和kmem_cache_alloc()所分配的實際記憶體空間的大小。
 * 6. ksize()存在的目的是因為有時候上述的3個函式所分配的記憶體空間大小，和設計師所指定的空間大小會不一樣。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("kcalloc() and ksize() sample. ");
MODULE_VERSION("1.0.0.build010919");

#define	MEM_VMALLOC_SIZE	8192

char *mem_spvm = (char *)NULL;

static int hello_init(void)
{
	printk(KERN_INFO "example (kcalloc() and ksize()) driver install. \n");
	mem_spvm = (char *)kcalloc(2, MEM_VMALLOC_SIZE, GFP_KERNEL);
	// 配置一個mem_spvm[2][MEM_VMALLOC_SIZE]的記憶體空間大小
	if (mem_spvm == (char *)NULL) {
		printk(KERN_ERR "kcalloc() failed!! \n");
		return -ENOMEM;
	}

	printk(KERN_INFO "kcalloc() successfully!! \n");
	// 輸出記憶體空間的起始位址
	printk(KERN_INFO "Start Address: 0x%08lx. \n", (unsigned long)mem_spvm);
	// 輸出該記憶體空間的大小
	printk(KERN_INFO "The actual allocated size is: %d. \n", ksize(mem_spvm));
	// 輸出位址偏移量為10的內容
	printk(KERN_INFO "The content of mem_spvm + 10 is: %d. \n", *(mem_spvm + 10));
	// 輸出位址偏移量為1000的內容
	printk(KERN_INFO "The content of mem_spvm + 1000 is: %d. \n", *(mem_spvm + 1000));

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example (kcalloc() and ksize()) driver uninstall. \n");
	kfree((void *)mem_spvm);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
