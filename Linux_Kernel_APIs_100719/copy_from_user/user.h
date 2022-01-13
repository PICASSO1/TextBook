#ifndef	_USER_H_
#define	_USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <strings.h>

#define	IOC_MAGIC	'e'	// "'e'xample". 

struct ioctl_cmd {
	unsigned int reg;
	unsigned int offset;
	unsigned int val;
};

#define	IOCTL_VAL		_IO(IOC_MAGIC, 0)
#define	IOCTL_VALSET	_IOW(IOC_MAGIC, 1, struct ioctl_cmd)
#define	IOCTL_VALGET	_IOR(IOC_MAGIC, 2, struct ioctl_cmd)
#define	IOCTL_VALGETSET	_IOWR(IOC_MAGIC, 3, struct ioctl_cmd)

#endif
