#ifndef _DEVONE_H_
#define _DEVONE_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/poll.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

#define	DRIVER_NAME	"devone"
#define	__FUNC__		__func__

#include <linux/ioctl.h>

struct ioctl_cmd {
	unsigned int reg;
	unsigned int offset;
	unsigned int val;
};

#define	IOC_MAGIC	'd'	// "'d'evone". 

#define	IOCTL_VAL		_IO(IOC_MAGIC, 0)
#define	IOCTL_VALSET		_IOW(IOC_MAGIC, 1, struct ioctl_cmd)
#define	IOCTL_VALGET	_IOR(IOC_MAGIC, 2, struct ioctl_cmd)
#define	IOCTL_VALGETSET	_IOWR(IOC_MAGIC, 3, struct ioctl_cmd)

#endif
