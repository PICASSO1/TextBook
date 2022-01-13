
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121018
 *
 * Date: 2018 / 12 / 10
 *
 * Description: 
 * 1. 這一個範例程序非常簡單，建立一個唯讀 (Read-Only)的Process File System (/proc/devone)：基本上就按照下面的程式碼範例來寫。
 *
 * 2. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define	DUMMY_BUFSIZ	4096

MODULE_LICENSE("Dual BSD/GPL");

static char dummy[DUMMY_BUFSIZ];

static int devone_read_proc(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int len = -1;

	printk(KERN_ALERT "page: %p; *start: %p; off: %d; count: %d; *eof: %d; data: %p \n", page, *start, (int)off, count, *eof, data);
	len = DUMMY_BUFSIZ;
	if (len > PAGE_SIZE)
		return -ENOBUFS;

	memcpy(page, dummy, len);
	*eof = 1;
	printk(KERN_ALERT "len = %d (%s) \n", len, __FUNCTION__);

	return len;
}

static int hello_init(void)
{
	struct proc_dir_entry *entry = (struct proc_dir_entry *)NULL;
	int i = -1;

	entry = create_proc_read_entry("devone", S_IRUGO | S_IWUGO, (struct proc_dir_entry *)NULL, devone_read_proc, (void *)NULL);
	if (entry == (struct proc_dir_entry *)NULL)
		printk(KERN_ALERT "devone: unable to create /proc entry!! \n");

	for (i = 0; i < DUMMY_BUFSIZ; i++)
		dummy[i] = 'A' + (i % 26);

	printk(KERN_ALERT "Driver install. \n");

	return 0;
}

static void hello_exit(void)
{
	remove_proc_entry("devone", (struct proc_dir_entry *)NULL);
	printk(KERN_ALERT "Driver uninstall. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
