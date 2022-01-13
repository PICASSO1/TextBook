 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	system("dmesg -c | tail -n 10");
	sleep(6);
	system("dmesg -c | tail -n 10");

	return;
}

#endif
