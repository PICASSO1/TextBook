
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
 * 1. 較底層的Buddy System / Allocator是以Page作為管理單位；而較上層的Slab Allocator則是以Cache作為管理單位。
 * 2. 而kmalloc()和kfree()就是從Slab Allocator實作出來的介面函式；若不想使用這兩個函式，直接取用Cache的話，就是用這一個範例kmem_cache_*()一系列的函式。
 * 3. static inline void *kmem_cache_zalloc(struct kmem_cache *k, gfp_t flags); kmem_cache_zalloc()和kmem_cache_alloc()的差異，是配置完記憶體空間之後，還會清空 (Zero Allocate)。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("kmem_cache_* function sample. ");
MODULE_VERSION("1.0.0.build010919");

#define	CACHESIZE	(128 * 1024)

void *ptr[10];
struct kmem_cache *cache = (struct kmem_cache *)NULL;

static int hello_init(void)
{
	int i = -1, ret = -1;

	printk(KERN_INFO "example (kmem_cache_*) driver install. \n");
	memset(ptr, 0x00, sizeof(ptr));
/*	struct kmem_cache *kmem_cache_create(
		const char *name, 
		size_t size, 
		size_t align, 
		unsigned long flags, 
		void (*ctor)(void *, struct kmem_cache *, unsigned long)
	);
	kmem_cache_create()函式只會建立Cache的容器，並不會配置記憶體空間。
*/	cache = (struct kmem_cache *)kmem_cache_create("example_picasso", CACHESIZE, 0, 0, NULL);
	if (cache == (struct kmem_cache *)NULL) {
		ret = -ENOMEM;
		goto error;
	}

	for (i = 0; i < 10; i++) {
	//	void *kmem_cache_alloc(struct kmem_cache *cachep, gfp_t flags); 這一個函式才是真正地在配置記憶體。
	//	ptr[i] = kmem_cache_alloc(cache, GFP_KERNEL);
		ptr[i] = kmem_cache_zalloc(cache, GFP_KERNEL);
		if (ptr[i] == (void *)NULL) {
			ret = -ENOMEM;
			goto error;
		}
	//	memset(ptr[i], 0x00, CACHESIZE);		// 用kmem_cache_zalloc()的話，就不必再用memset()了！
		printk(KERN_INFO "ptr[%d]: 0x%p \n", i, ptr[i]);
	}

	return 0;

error:
	for (i = 0; i < 10; i++) {
		if (ptr[i] != (void *)NULL)
			kmem_cache_free((void *)cache, ptr[i]);
			// 相對於kmem_cache_alloc()函式，kmem_cache_free()函式是用來釋放Cache的記憶體空間。
	}

	if (cache != (struct kmem_cache *)NULL)
		kmem_cache_destroy(cache);
		// 相對於kmem_cache_create()函式，kmem_cache_destroy()函式是用來取消Cache的容器。

	return ret;
}

static void hello_exit(void)
{
	int i = -1;

	printk(KERN_INFO "example (kmem_cache_*) driver uninstall. \n");
	for (i = 0; i < 10; i++) {
		if (ptr[i] != (void *)NULL)
			kmem_cache_free((void *)cache, ptr[i]);
	}

	if (cache != (struct kmem_cache *)NULL)
		kmem_cache_destroy(cache);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
