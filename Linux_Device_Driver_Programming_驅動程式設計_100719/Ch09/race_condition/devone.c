
/**
 * File Name: devone.c
 *
 * CopyLeft (C) 2015-2018, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build122718
 *
 * Date: 2018 / 12 / 27
 *
 * Description: 
 * 1. 這一個範例看得不是很懂；但看得出來是用兩個Timer (計時器)來製造出一個Race Condition (Racing, 競走現像)的狀況。
 * 2. 在Module Entry Point (insmod)動作很簡單，就只是建立一個/dev/devone；
 * 3. 真正在運作的時候，是在開檔 (open)和讀檔 (read)的時候；所以我們可以用指令"hexdump -C -n 16 /dev/devone"來代替這兩個動作。
 * 4. 在開檔的時候，會初始化我們自訂資料的一些結構成員 (spinlock_t, wait_queue_head_t)，定且設定兩個Timer (TimeOut)。
 * 5. 第一個條件是：先把timeout_done這一個Flag先設成0，並重新啟動計時器 (devone_timeout) -- 10秒鐘之後timeout_done就會被設成1；
 * 6. 第二個條件是：執行Kick DMA，會把dma_done這一個Flag先設成0，也重新啟動計時器(devone_irq) -- 3秒鐘之後dma_done就會被設成1；
 * 7. 執行wait_event()讓Process Context (devone_read())進入睡眠狀態，直到timeout_done == 1或是dma_done == 1才會被喚醒。
 * 8. 因為timeout_value設成10，而irq_value設成3；dma_done會先被設為1而被喚醒，所以devone_irq()函式會先被呼叫到。
 * 9. 同理，Condition 1和Condition 2的條件互換的話，結果就會相反。
 *
 * 10. (To do something....)
 *
(*)?*/

#include "devone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("Race Condition (Racing) sample. ");
MODULE_VERSION("1.0.0.build122718");

static unsigned int timeout_value = 10;
static unsigned int irq_value = 3;

// Driver Parameters
module_param(timeout_value, uint, 0);
module_param(irq_value, uint, 0);

static int devone_devs = 1;
static int devone_major = 0;
static struct cdev devone_cdev;

struct devone_data {
	struct timer_list timeout;
	struct timer_list irq;
	spinlock_t lock;
	wait_queue_head_t wait;
	int dma_done;
	int timeout_done;
};

static void devone_timeout(unsigned long arg)
{
	struct devone_data *dev = (struct devone_data *)arg;
	unsigned long flags = 0UL;

	spin_lock_irqsave(&dev->lock, flags);
	printk(KERN_ALERT "%s called. \n", __FUNCTION__);
	dev->timeout_done = 1;
	wake_up(&dev->wait);
	spin_unlock_irqrestore(&dev->lock, flags);

	return;
}

static void devone_irq(unsigned long arg)
{
	struct devone_data *dev = (struct devone_data *)arg;
	unsigned long flags = 0UL;

	spin_lock_irqsave(&dev->lock, flags);
	printk(KERN_ALERT "%s called. \n", __FUNCTION__);
	dev->dma_done = 1;
	wake_up(&dev->wait);
	spin_unlock_irqrestore(&dev->lock, flags);

	return;
}

static void devone_dma_transfer(struct devone_data *dev)
{
	dev->dma_done = 0;
	mod_timer(&dev->irq, jiffies + (irq_value * HZ));

	return;
}

ssize_t devone_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;
	int i = -1, retval = -1;
	unsigned char val = 0xBC;
	// Start Timer (condition 1)
	dev->timeout_done = 0;
	mod_timer(&dev->timeout, jiffies + (timeout_value * HZ));
	// Kick DMA (condition 2)
	devone_dma_transfer(dev);
	// Sleep process with condition
	wait_event(dev->wait, (dev->dma_done == 1) || (dev->timeout_done == 1));
	// Cancel Timer
	del_timer_sync(&dev->timeout);
	if (dev->timeout_done == 1)	// Timeout occurred
		return -EIO;
	// Store read data
	for (i = 0; i < count; i++) {
		if (copy_to_user(&buf[i], &val, 1) != 0) {
			retval = -EFAULT;
			goto out;
		}
	}
	retval = count;
out:
	return retval;
}

int devone_open(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)NULL;

	dev = (struct devone_data *)kmalloc(sizeof(struct devone_data), GFP_KERNEL);
	if (dev == (struct devone_data *)NULL)
		return -ENOMEM;
	// Initialize members
	spin_lock_init(&dev->lock);
	init_waitqueue_head(&dev->wait);

	dev->dma_done = 0;
	dev->timeout_done = 0;

	init_timer(&dev->timeout);
	dev->timeout.function = devone_timeout;
	dev->timeout.data = (unsigned long)dev;

	init_timer(&dev->irq);
	dev->irq.function = devone_irq;
	dev->irq.data = (unsigned long)dev;

	filp->private_data = (struct file *)dev;

	return 0;
}

int devone_close(struct inode *inode, struct file *filp)
{
	struct devone_data *dev = (struct devone_data *)filp->private_data;

	if (dev != (struct devone_data *)NULL) {
		del_timer_sync(&dev->timeout);
		del_timer_sync(&dev->irq);
		kfree(dev);
	}

	return 0;
}

struct file_operations devone_fops = {
	.open = devone_open, 
	.release = devone_close, 
	.read = devone_read, 
};

static int hello_init(void)
{
	dev_t dev = MKDEV(devone_major, 0);
	int ret = -1, major = -1, err = -1;

	ret = alloc_chrdev_region(&dev, 0, devone_devs, "devone");
	if (ret < 0)
		return ret;
	devone_major = major = MAJOR(dev);

	cdev_init(&devone_cdev, &devone_fops);
	devone_cdev.owner = THIS_MODULE;
	devone_cdev.ops = &devone_fops;
	err = cdev_add(&devone_cdev, MKDEV(devone_major, 0), 1);
	if (err)
		return err;

	printk(KERN_ALERT "devone driver (major: %d) install. \n", major);
	printk(KERN_ALERT "timeout %u irq %u timer (%s) \n", timeout_value, irq_value, __FUNCTION__);

	return 0;
}

static void hello_exit(void)
{
	dev_t dev = MKDEV(devone_major, 0);

	printk(KERN_ALERT "devone driver uninstall. \n");
	cdev_del(&devone_cdev);
	unregister_chrdev_region(dev, devone_devs);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
