
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
 * 1. 除了之前的proc_ro / proc_rw之外，Linux Kernel還提供了另外一種實作方式：seq_file
 * 2. 但seq_file指能夠Read-Only (唯讀)，無法寫入 (Read-Write)。
 * 3. seq_file的程序碼架構就是按照這一個範例來呈現；至於它在寫啥，課本上有寫。
 * 4. seq_file和procfs的差異在於procfs的資料量不能夠超過Kernel的Page Size (記憶體分頁的大小)。
 * 5. 此外，seq_file的列印方式，不能夠用printk(); 要用seq_file所提供的API: seq_printf(); / seq_putc(); / seq_puts(); . 
 *
 * 5. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *data_message[] = {
	"Fedora Core", 
	"Red Hat Enterprise Linux", 
	"Debian", 
	"Vine", 
	"Ubuntu", 
	(char *)NULL
};

static void *as_start(struct seq_file *m, loff_t *pos)
{
	loff_t n = *pos;
	char **p;
	int i = -1;

	printk(KERN_ALERT "%lld (%s) \n", n, __FUNCTION__);
	if (n == 0)
		seq_printf(m, "=== seq_file header === \n");

	p = data_message;
	for (i = 0; p[i] != (char *)NULL; i++) {
		n--;
		if (n < 0)
			return (void *)(i + 1);
	}

	return (void *)0;
}

static void as_show(struct seq_file *m, void *p)
{
	int n = (int)p - 1;

	printk(KERN_ALERT "%u (%s) \n", n, __FUNCTION__);
	seq_printf(m, "[%d] %s \n", n, data_message[n]);

	return;
}

static void *as_next(struct seq_file *m, void *p, loff_t *pos)
{
	int n = (int)p;
	char **ptr;

	printk(KERN_ALERT "%u (%s) \n", n, __FUNCTION__);
	(*pos)++;
	ptr = data_message;
	if (ptr[n] != (char *)NULL)
		return (void *)(n + 1);

	return (void *)0;
}

static void as_stop(struct seq_file *m, void *p)
{
	int n = (int)p;

	printk(KERN_ALERT "%u (%s) \n", n, __FUNCTION__);

	return;
}

// seq_file handler
static struct seq_operations devone_seq_op = {
	.start = as_start, 
	.show = as_show, 
	.next = as_next, 
	.stop = as_stop, 
};

static int devone_proc_open(struct inode *inode, struct file *file)
{
	return seq_open(file, &devone_seq_op);
}

// procfs handler
static struct file_operations devone_operations = {
	.open = devone_proc_open, 
	.read = seq_read, 
	.llseek = seq_lseek, 
	.release = seq_release, 
};

static int hello_init(void)
{
	struct proc_dir_entry *entry = (struct proc_dir_entry *)NULL;

	entry = create_proc_entry("devone", S_IRUGO | S_IWUGO, (struct proc_dir_entry *)NULL);
	if (entry != (struct proc_dir_entry *)NULL)
		entry->proc_fops = &devone_operations;

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
