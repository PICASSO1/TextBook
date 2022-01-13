 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	printf("cat -n /proc/devone: \n");
	system("cat -n /proc/devone; ");

	printf("echo 1 1> /proc/devone: \n");
	system("echo 1 1> /proc/devone; ");

	printf("cat -n /proc/devone: \n");
	system("cat -n /proc/devone; ");

	return;
}

#endif
