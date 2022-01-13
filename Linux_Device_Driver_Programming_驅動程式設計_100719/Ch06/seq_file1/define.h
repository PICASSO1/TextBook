 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("cat -n /proc/devone");
	system("dmesg -c");

	return;
}

#endif
