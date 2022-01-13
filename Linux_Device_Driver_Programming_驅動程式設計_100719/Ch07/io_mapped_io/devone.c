
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
 * 1. 這一支程序展現了"I/O mapped I/O"的寫法，要用request_region(); 和release_region(); 這兩隻支函式；
 * 2. 但是，第一個參數"resource_size_t"是指I/O Space Port Address，這一個並不能亂寫 (所以這一個範例並無意義)。
 * 3. 第2個參數是只要有幾個I/O Port，如這裡是寫"4"，在/proc/ioports就會看到："2f00-2f03: devone". 
 * 4. 因為實際上並沒有0x2F00這個I/O Port Address，所以這一支程序make完了之後，insmod devone.ko在dmesg -c會有警告訊息，只能reboot了！
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/ioport.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");

static int hello_init(void)
{
	printk(KERN_ALERT "Driver install. But I have an I/O mapped I/O. \n");

	if (request_region(0x2F00, 4, "devone") != 0) {
		return -EBUSY;
	}

	return 0;
}

static void hello_exit(void)
{
	release_region(0x2F00, 4);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
