 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("cat /proc/devone | wc -c; dmesg -c | tail -n 15");

	return;
}

#endif
