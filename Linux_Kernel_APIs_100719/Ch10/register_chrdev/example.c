
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
 * 1. 這一支Kernel Space的程序，展現了register_chrdev()和unregister_chrdev()的應用 (Character Device)。
 * 2. 這兩支函式，會在/proc/device留下註冊的紀錄；
 * 3. 早期的linux-2.4.x，還是會用這種寫法；
 * 4. 這兩支函式的第1個參數，是傳進去要向Linux Kernel註冊的Major ID；
 * 5. 所比換句話說，當執行"mknod /dev/(Device Name) b/c (Major ID) (Minor ID)"時，兩者的Major ID必須要相同；
 * 6. 這就是所謂的Static Register (靜態註冊)。
 * 7. Linux的Major ID是12-bit (0~4095)，Minor ID是20-bit (0~104,8575)；但是0和255這兩個編號被保留了，設計師不能夠用。
 * 8. 如果不想記下因系統差異而導致哪些ID不能用，現在流行的作法則是改用Dynamic Register (動態註冊)。
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("register_chrdev() and unregister_chrdev() sample. ");
MODULE_VERSION("1.0.0.build010919");

#define	DRIVER_NAME	"example"
#define	MAJOR_ID		249

struct file_operations example_fops = { };

static int hello_init(void)
{
	int ret = 0;

	ret = register_chrdev(MAJOR_ID, DRIVER_NAME, &example_fops);
	if (ret < 0) {
		printk(KERN_ERR "%s (register_chrdev() and unregister_chrdev()) driver registration error!! \n", DRIVER_NAME);
		goto error;
	}

	printk(KERN_INFO "%s (register_chrdev() and unregister_chrdev()) driver (major: %d) installed. \n", DRIVER_NAME, MAJOR_ID);

error:
	return ret;
}

static void hello_exit(void)
{
	unregister_chrdev(MAJOR_ID, DRIVER_NAME);

	printk(KERN_INFO "%s (register_chrdev() and unregister_chrdev()) driver (major: %d) uninstalled. \n", DRIVER_NAME, MAJOR_ID);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
