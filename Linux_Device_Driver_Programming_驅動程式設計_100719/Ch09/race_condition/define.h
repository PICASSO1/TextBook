 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("hexdump -C -n 16 /dev/devone; dmesg -c | tail -n 10; ");

	return;
}

#endif
