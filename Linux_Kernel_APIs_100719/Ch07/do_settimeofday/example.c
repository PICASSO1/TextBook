
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011519
 *
 * Date: 2019 / 01 / 15
 *
 * Description: 
 * 1. 這一個範例是介紹do_settimeofday()函式的用法--實用性比do_gettimeofday()來的更差。
 * 2. 要留意的是使用do_settimeofday()函式設定時間，讀取時並非使用do_gettimeofday()，而是getnstimeofday()函式 (Get Nano Second Time of Day)。
 * 3. do_settimeofday()和getnstimeofday()所傳進去的時間參數是Time Spec:
 *     struct timespec {
 *         time_t tv_sec;		// time_t: 秒。
 *         long tv_nsec;		// long: 奈秒，10的-9次方，十億分之一秒，1 / 1,000,000,000
 *     };
 * 4. 而do_gettimeofday()所傳進去的時間參數是Time Value:
 *     struct timeval {
 *         time_t tv_sec;		// time_t: 秒。
 *         suseconds_t tv_usec;	// suseconds_t: 微秒，10的-6次方，百萬分之一秒，1 / 100,0000
 *     };
 * 5. 所以，論精準度而言，Time Spec比Time Value要來得更嚴謹。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("do_settimeofday() and getnstimeofday() sample. ");
MODULE_VERSION("1.0.0.build011519");

static int hello_init(void)
{
	struct timespec now0 = {
		.tv_sec = 111111111, 
		.tv_nsec = 999999999 
	};
	struct timespec now1 = {
		.tv_sec = 0, 
		.tv_nsec = 0 
	};

	printk(KERN_INFO "example driver (%s) installed. \n", __FUNCTION__);
	if (do_settimeofday(&now0) != 0) {
		printk(KERN_ERR "do_settimeofday() function failed!! \n");
		return 1;
	}

	getnstimeofday(&now1);
	printk(KERN_NOTICE "The seconds of the day is: %ld. \n", now1.tv_sec);
	printk(KERN_NOTICE "The nanoseconds of the day is: %ld. \n", now1.tv_nsec);
	printk(KERN_INFO "do_settimeofday() feature testing done. \n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example driver (%s) uninstalled. \n", __FUNCTION__);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
