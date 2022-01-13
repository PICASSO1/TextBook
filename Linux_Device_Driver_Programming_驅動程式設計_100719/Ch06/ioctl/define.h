 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

#define	DEVFILE		"/dev/devone"

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

void showDmesg(void)
{
	system("dmesg -c | tail -n 20");

	return;
}

void read_buffer(int fd)
{
	unsigned char buf[64];
	int ret = -1, i = -1;

	memset(buf, '\0', sizeof(unsigned char) * 64);
	ret = read(fd, buf, sizeof(unsigned char) * 64);
	if (ret == -1)
		perror("read");

	for (i = 0; i < ret; i++)
		printf("%02X ", buf[i]);

	printf("\n");

	return;
}

#endif
