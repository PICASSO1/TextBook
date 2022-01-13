
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build012319
 *
 * Date: 2019 / 01 / 23
 *
 * Description: 
 * 1. 這一個範例是介紹wait_queue_head_t資料型態和初始化wait_queue_head_t的init_waitqueue_head()函式；與這兩者相關的功能則是sleep_on()
 *     和wake_up()一系列的函式。
 * 2. struct __wait_queue_head {	// <linux/wait.h>
 *         spinlock_t lock;
 *         struct list_head task_list;
 *     };
 *     typedef struct __wait_queue_head wait_queue_head_t;
 * 
 * 3. struct list_head {			// <linux/list.h>
 *         struct list_head *next; 
 *         struct list_head *prev;
 *     };
 * 
 * 4. void init_waitqueue_head(wait_queue_head_t *q); 	// <linux/wait.h>
 *     經過init_waitqueue_head()函式初始化過後的wait_queue_head_t *q，使參數q的task_list欄位的next和prev成員都指向自己。從範例中可以看出
 *     初始化前next和prev的指標都是空的；初始化過後，因為都指向自己，所以記憶體位址都一樣！
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/wait.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("init_waitqueue_head() function sample. ");
MODULE_VERSION("1.0.0.build012319");

#define	DRIVER_NAME	"example"

wait_queue_head_t example_wq; 

static int hello_init(void)
{
	if (example_wq.task_list.next == NULL || example_wq.task_list.prev == NULL)
		printk(KERN_INFO "before init_waitqueue_head() .... \n");

	init_waitqueue_head(&example_wq); 
	printk(KERN_INFO "%s driver installed (example_wq.task_list.next: 0x%08X; example_wq.task_list.prev: 0x%08X). \n", \
		DRIVER_NAME, (unsigned int)example_wq.task_list.next, (unsigned int)example_wq.task_list.prev);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "%s driver uninstalled. \n", DRIVER_NAME);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
