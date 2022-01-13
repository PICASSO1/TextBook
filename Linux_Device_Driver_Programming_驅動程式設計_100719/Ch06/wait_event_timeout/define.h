 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("insmod devone.ko; dmesg -c");

	return;
}

#endif
