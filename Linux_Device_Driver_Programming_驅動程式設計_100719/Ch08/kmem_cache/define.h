 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	printf("\n");
	printf("ls -l /sys/module/devone/ \n");
	system("ls -l /sys/module/devone/; ");
	printf("\n");

	printf("dmesg -c | tail -n 10 \n");
	system("dmesg -c | tail -n 10; ");
	printf("\n");

	return;
}

#endif
