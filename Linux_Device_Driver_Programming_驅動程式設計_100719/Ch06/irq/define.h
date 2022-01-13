 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("insmod devone.ko; head -n 20 /proc/interrupts; dmesg -c");

	return;
}

#endif
