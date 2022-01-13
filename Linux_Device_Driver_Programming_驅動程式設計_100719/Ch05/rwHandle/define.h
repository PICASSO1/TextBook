 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

#define	DEVFILE		"/dev/devone"
#define	DEVCOUNT	5

void showDmesg(void)
{
	system("dmesg -c | tail -n 15");

	return;
}

int open_file(char *filename)
{
	int fd = -1;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		perror("open");

	return fd;
}

void close_file(int fd)
{
	int ret = -1;

	ret = close(fd);
	if (ret != 0)
		perror("close");

	return;
}

void read_file(int fd)
{
	unsigned char buf[8], *p = (unsigned char *)NULL;
	ssize_t ret = 0;

	memset(buf, 0x00, sizeof(unsigned char) * 8);
	ret = read(fd, buf, sizeof(unsigned char) * 8);
	if (ret > 0) {
		p = buf;
		while (ret--)
			printf("%02X ", *(p++));
	}
	else
		perror("read");
	printf("\n");

	return;
}

void write_file(int fd, unsigned char val)
{
	ssize_t ret = 0;

	ret = write(fd, &val, sizeof(unsigned char));
	if (ret <= 0)
		perror("write");

	return;
}

#endif
