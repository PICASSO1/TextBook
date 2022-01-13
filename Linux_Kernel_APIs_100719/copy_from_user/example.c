#include "example.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("multi-Minor sample. ");
MODULE_VERSION("1.0.0.build011719");

#define	DRIVER_NAME	"example"

static int example_major = 0;
static int example_base_minor = 0;
static int example_device_count = 4;
module_param(example_major, uint, 0);
dev_t dev = MKDEV(0, 0);
struct cdev *example_cdev = (struct cdev *)NULL;

// ============================================================================
// User Process open(), close(), read(), write(), ioctl(), /dev/example1 (MajorID, MinorID: 7). 
static int one_open(struct inode *inode, struct file *file)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	exData = (struct example_data *)kzalloc(sizeof(struct example_data), GFP_KERNEL);
	if (exData == (struct example_data *)NULL)
		return -ENOMEM;
	
	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
	return 0;
}

static int one_close(struct inode *inode, struct file *file)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (exData->val != (unsigned char *)NULL)
		kfree((void *)exData->val);
	
	if (exData != (struct example_data *)NULL) 
		kfree((void *)exData);

	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
	return 0;
}

ssize_t one_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (copy_to_user((int __user *)buf, exData->val, count) != 0)
		return -EFAULT;
	
	file->private_data = (void *)exData;

//	printk(KERN_INFO "%s: PID: %d; file->private_data: %p \n", __FUNCTION__, current->pid, file->private_data);

	return count;
}

ssize_t one_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (copy_from_user(exData->val, (int __user *)buf, count) != 0)
		return -EFAULT;

	printk(KERN_INFO "%s: exData->val: %s (%d) \n", __FUNCTION__, exData->val, count);
	
	file->private_data = (void *)exData;

//	printk(KERN_INFO "%s: PID: %d; file->private_data: %p \n", __FUNCTION__, current->pid, file->private_data);

	return count;
}

int one_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	struct example_data *exData = (struct example_data *)file->private_data;
	int retval = 0;
	struct ioctl_cmd data;

	memset(&data, 0, sizeof(struct ioctl_cmd));
	switch (cmd) {
		case IOCTL_VALSET:
			if (capable(CAP_SYS_ADMIN) == 0) {
				retval = -EPERM;
				goto error;
			}

			if (access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd)) == 0) {
				retval = -EFAULT;
				goto error;
			}

			if (copy_from_user(&data, (int __user *)arg, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			printk(KERN_INFO "%s: ioctl(): cmd.val = 0x%02X \n", __FUNCTION__, data.val);

			data.val = 0xEE;
			if (copy_to_user((int __user *)arg, &data, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			// 為了接下來write的行為，先配置記憶體空間。
			exData->val = (unsigned char *)kzalloc(sizeof(unsigned char) * 32, GFP_KERNEL);
			if (exData->val == (unsigned char *)NULL) {
				retval = -ENOMEM;
				goto error;
			}
			break;
		case IOCTL_VALGET:
			if (access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd)) == 0) {
				retval = -EFAULT;
				goto error;
			}

			if (copy_from_user(&data, (int __user *)arg, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			printk(KERN_INFO "%s: ioctl(): cmd.val = 0x%02X \n", __FUNCTION__, data.val);

			data.val = 0xFF;
			if (copy_to_user((int __user *)arg, &data, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			break;
		case IOCTL_VAL:
		case IOCTL_VALGETSET:
		default:
			retval = -ENOTTY;
			break;
	}
	
	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
error:
	return retval;
}

struct file_operations one_fops = {
	.open = one_open, 
	.release = one_close, 
	.read = one_read, 
	.write = one_write, 
	.ioctl = one_ioctl, 
};

// ============================================================================
// User Process open(), close(), read(), write(), ioctl(), /dev/example2 (MajorID, MinorID: 8). 
static int two_open(struct inode *inode, struct file *file)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	exData = (struct example_data *)kzalloc(sizeof(struct example_data), GFP_KERNEL);
	if (exData == (struct example_data *)NULL)
		return -ENOMEM;
	
	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
	return 0;
}

static int two_close(struct inode *inode, struct file *file)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (exData->val != (unsigned char *)NULL)
		kfree((void *)exData->val);
	
	if (exData != (struct example_data *)NULL) 
		kfree((void *)exData);

	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
	return 0;
}

ssize_t two_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (copy_to_user((int __user *)buf, exData->val, count) != 0)
		return -EFAULT;
	
	file->private_data = (void *)exData;

//	printk(KERN_INFO "%s: PID: %d; file->private_data: %p \n", __FUNCTION__, current->pid, file->private_data);

	return count;
}

ssize_t two_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct example_data *exData = (struct example_data *)file->private_data;

	if (copy_from_user(exData->val, (int __user *)buf, count) != 0)
		return -EFAULT;

	printk(KERN_INFO "%s: exData->val: %s (%d) \n", __FUNCTION__, exData->val, count);
	
	file->private_data = (void *)exData;

//	printk(KERN_INFO "%s: PID: %d; file->private_data: %p \n", __FUNCTION__, current->pid, file->private_data);

	return count;
}

int two_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	struct example_data *exData = (struct example_data *)file->private_data;
	int retval = 0;
	struct ioctl_cmd data;

	memset(&data, 0, sizeof(struct ioctl_cmd));
	switch (cmd) {
		case IOCTL_VALSET:
			if (capable(CAP_SYS_ADMIN) == 0) {
				retval = -EPERM;
				goto error;
			}

			if (access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd)) == 0) {
				retval = -EFAULT;
				goto error;
			}

			if (copy_from_user(&data, (int __user *)arg, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			printk(KERN_INFO "%s: ioctl(): cmd.val = 0x%02X \n", __FUNCTION__, data.val);

			data.val = 0xBB;
			if (copy_to_user((int __user *)arg, &data, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			// 為了接下來write的行為，先配置記憶體空間。
			exData->val = (unsigned char *)kzalloc(sizeof(unsigned char) * 32, GFP_KERNEL);
			if (exData->val == (unsigned char *)NULL) {
				retval = -ENOMEM;
				goto error;
			}
			break;
		case IOCTL_VALGET:
			if (access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd)) == 0) {
				retval = -EFAULT;
				goto error;
			}

			if (copy_from_user(&data, (int __user *)arg, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			printk(KERN_INFO "%s: ioctl(): cmd.val = 0x%02X \n", __FUNCTION__, data.val);

			data.val = 0xDD;
			if (copy_to_user((int __user *)arg, &data, sizeof(struct ioctl_cmd)) != 0) {
				retval = -EFAULT;
				goto error;
			}
			break;
		case IOCTL_VAL:
		case IOCTL_VALGETSET:
		default:
			retval = -ENOTTY;
			break;
	}
	
	file->private_data = (void *)exData;

/*	printk(KERN_INFO "%s: imajor(inode): %d; iminor(inode): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", \
		__FUNCTION__, imajor(inode), iminor(inode), current->pid, inode->i_private, file->private_data);
*/
error:
	return retval;
}

struct file_operations two_fops = {
	.open = two_open, 
	.release = two_close, 
	.read = two_read, 
	.write = two_write, 
	.ioctl = two_ioctl, 
};

// ============================================================================
static int example_open(struct inode *inode, struct file *file)
{
/*	printk(KERN_INFO "%s: MAJOR(inode->i_rdev): %d; MINOR(inode->i_rdev): %d; PID: %d; inode->i_private: %p; file->private_data: %p \n", 
		__FUNCTION__, MAJOR(inode->i_rdev), MINOR(inode->i_rdev), current->pid, inode->i_private, file->private_data);
*/
	switch (iminor(inode)) {
		case 7:
			file->f_op = &one_fops;
			break;
		case 8:
			file->f_op = &two_fops;
			break;
		default:
			return -ENXIO;
	}

	if (file->f_op && file->f_op->open)
		return file->f_op->open(inode, file);

	return 0;
}

struct file_operations example_fops = {
	.open = example_open, 
};

static int hello_init(void)
{
	int region_err = 0, add_err = 0;

	region_err = alloc_chrdev_region(&dev, 6, example_device_count, DRIVER_NAME);
	if (region_err < 0)
		goto error;
	example_major = MAJOR(dev);
	example_base_minor = MINOR(dev);

	example_cdev = cdev_alloc();
	if (example_cdev == (struct cdev *)NULL)
		goto error;

	cdev_init(example_cdev, &example_fops);	
	example_cdev->owner = THIS_MODULE;
	add_err = cdev_add(example_cdev, MKDEV(example_major, example_base_minor), example_device_count);
	if (add_err != 0)
		goto error;

	printk(KERN_INFO "%s driver installed (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	return 0;
error:
	if (add_err != 0)
		cdev_del(example_cdev);

	if (example_cdev == (struct cdev *)NULL)
		kfree((void *)example_cdev);

	if (region_err < 0)
		unregister_chrdev_region(dev, example_device_count);

	return -1;
}

static void hello_exit(void)
{
	cdev_del(example_cdev);

	if (example_cdev != (struct cdev *)NULL)
		kfree((void *)example_cdev);

	unregister_chrdev_region(dev, example_device_count);

	printk(KERN_INFO "%s driver uninstalled (Major ID: %d; Base Minor ID: %d; Device Count: %d). \n", \
		DRIVER_NAME, example_major, example_base_minor, example_device_count);

	return;
}

module_init(hello_init);
module_exit(hello_exit);
