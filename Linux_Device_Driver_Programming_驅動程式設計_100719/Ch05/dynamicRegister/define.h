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

#endif
