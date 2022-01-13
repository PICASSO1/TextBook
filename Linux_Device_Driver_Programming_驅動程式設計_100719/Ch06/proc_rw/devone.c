
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121118
 *
 * Date: 2018 / 12 / 11
 *
 * Description: 
 * 1. 這一個範例程序延續上一個唯讀 (Read-Only)的Process File System (/proc/devone)；
 * 2. 這一個範例則是可讀寫 (Read-Write)的Process File System (/proc/devone)。
 * 3. 寫法如下：
 *
 * 4. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>

#define	DUMMY_BUFSIZ	4096

MODULE_LICENSE("Dual BSD/GPL");

static int devone_flag  = 0;

static int devone_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int len = -1;

	printk(KERN_ALERT "%s called. \n", __FUNCTION__);
	if (off > 0)
		len = 0;
	else
		len = sprintf(page, "%d \n", devone_flag);

	return len;
}

int devone_proc_write(struct file *file, const char *buffer, unsigned long count, void *data)
{
	char buf[16];
	unsigned long len = count;
	int n = -1;

	printk(KERN_ALERT "%d (%s) \n", (int)len, __FUNCTION__);
	if (len >= (sizeof(char) * 16))
		len = (sizeof(char) * 16) - 1;

	if (copy_from_user(buf, buffer, len) != 0)
		return -EFAULT;
	buf[len] = '\0';

	n = simple_strtol(buf, NULL, 10);
	if (n == 0)
		devone_flag = 0;
	else
		devone_flag = 1;

	return len;
}

static int hello_init(void)
{
	struct proc_dir_entry *entry = (struct proc_dir_entry *)NULL;

	entry = create_proc_entry("devone", 0666, (struct proc_dir_entry *)NULL);
	if (entry == (struct proc_dir_entry *)NULL)
		printk(KERN_ALERT "devone: unable to create /proc entry!! \n");

	entry->read_proc = devone_proc_read;
	entry->write_proc = devone_proc_write;
//	entry->owner = THIS_MODULE;

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
