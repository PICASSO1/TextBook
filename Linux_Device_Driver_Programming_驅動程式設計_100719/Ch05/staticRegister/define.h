 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

#define	DEVFILE	"/dev/devone"

void showDmesg(void)
{
	system("dmesg -c | tail -n 10");

	return;
}

#endif
