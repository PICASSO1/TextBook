
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build121418
 *
 * Date: 2018 / 12 / 14
 *
 * Description: 
 * 1. seq_file的另外一個範例！
 *
 * x. (To do something....)
 *
(*)?*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/version.h>

MODULE_LICENSE("Dual BSD/GPL");

static void *as_start(struct seq_file *m, loff_t *pos)
{
	loff_t n = *pos;
	struct task_struct *p = (struct task_struct *)NULL;

	printk(KERN_ALERT "%lld (%s) \n", n, __FUNCTION__);
	if (n == 0)
		seq_printf(m, "=== seq_file headre === \n");
	// Acquire a read-only spinlock. 
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18))
	read_lock(&tasklist_lock);
#else
	rcu_read_lock();
#endif
	if (n == 0)
		return (&init_task);		// swapper procsee

	for_each_process(p) {		// init later process
		n--;
		if (n <= 0)
			return (void *)p;
	}

	return (void *)0;
}

static int as_show(struct seq_file *m, void *p)
{
	struct task_struct *tp = (struct task_struct *)p;

	printk(KERN_ALERT "%p (%s) \n", tp, __FUNCTION__);
	seq_printf(m, "[%s] pid = %d \n", tp->comm, tp->pid);
	seq_printf(m, "     tgid = %d \n", tp->tgid);
	seq_printf(m, "     state = %ld \n", tp->state);
	seq_printf(m, "     mm = 0x%p \n", tp->mm);
	seq_printf(m, "     utime = %lu \n", tp->utime);
	seq_printf(m, "     stime = %lu \n", tp->stime);
//	seq_printf(m, "     oomkilladj = %d \n", tp->oomkilladj);
	seq_printf(m, "\n");

	return 0;
}

static void *as_next(struct seq_file *m, void *p, loff_t *pos)
{
	struct task_struct *tp = (struct task_struct *)p;

	printk(KERN_ALERT "%lld (%s) \n", *pos, __FUNCTION__);
	(*pos)++;
	tp = next_task(tp);
	if (tp == &init_task)
		return (void *)NULL;

	return (void *)tp;
}

static void as_stop(struct seq_file *m, void *p)
{
	printk(KERN_ALERT "%u (%s) \n", p, __FUNCTION__);
	// Release a read-only spinlock. 
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18))
	read_unlock(&tasklist_lock);
#else
	rcu_read_unlock();
#endif
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
