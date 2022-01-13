
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122918
 *
 * Date: 2018 / 12 / 29
 *
 * Description: 
 * 1. 這是一個簡單的atomic範例；至於什麼是atomic可以參考課本上的說明。
 * 2. atomic還有一系列的相關函式，課本就只有介紹，並無範例。
 *
 * 3. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("atomic sample. ");
MODULE_VERSION("1.0.0.build122918");

atomic_t counter = ATOMIC_INIT(0);

static int hello_init(void)
{
	int n = 0;

	atomic_inc(&counter);
	n = atomic_read(&counter);

	printk(KERN_ALERT "n = %d \n", n);
	if (atomic_dec_and_test(&counter) != 0)
		printk(KERN_ALERT "atomic_dec_and_test(): TRUE. \n");
	else
		printk(KERN_ALERT "atomic_dec_and_test(): FALSE. \n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "devone driver uninstall. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
