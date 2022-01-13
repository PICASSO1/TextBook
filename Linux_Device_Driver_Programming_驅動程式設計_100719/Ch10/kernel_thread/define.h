 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("insmod devone.ko; ");
	system("dmesg -c | tail -n 10; ");
	system("ps aux | grep --color \"devone\"; ");
	system("rmmod devone; ");
	system("dmesg -c | tail -n 10; ");

	return;
}

#endif
