 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

#define	DEVFILE		"/dev/devone"

void showDmesg(void)
{
	system("hexdump -C -v -n 32 /dev/devone");

	return;
}

#endif
