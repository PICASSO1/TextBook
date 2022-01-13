
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
 * 1. 這一支Linux Kernel Space的程序很簡單，原本的printk(); 只能透過dmesg指令才能看到；現在可以導入到TTY Console！！
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");

static void hook_tty_console(char *msg)
{
	struct tty_struct *tty = (struct tty_struct *)current->signal->tty;

	if (tty != (struct tty_struct *)NULL) {
		// 舊版linux-2.4.x的寫法；
	/*	((tty->driver)->write) (tty, msg, strlen(msg));
		((tty->driver)->write) (tty, "\r\n", 2);
	*/	// 新版linux-2.6.x的寫法！
		((tty->driver)->ops->write)(tty, msg, strlen(msg));
		((tty->driver)->ops->write)(tty, "\r\n", 2);
	}

	return;
}

static int hello_init(void)
{
	printk(KERN_ALERT "Driver install. Wa~Ha~Ha~Ha~Ha~Ha~ \n");

	hook_tty_console("This message is written by sample driver. ");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Driver uninstall. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
