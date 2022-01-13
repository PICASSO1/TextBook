 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("dmesg -c | tail -n 10");
	system("head -n 20 /proc/interrupts; ");

	return;
}

#endif
