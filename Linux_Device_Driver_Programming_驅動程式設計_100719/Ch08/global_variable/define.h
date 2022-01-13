 #ifndef	_DEFINE_H_
#define	_DEFINE_H_

void showDmesg(void)
{
	printf("cat -n devone.map \n");
	system("cat -n ./devone.map ");
	printf("\n");

	printf("cat -n Module.symvers \n");
	system("cat -n Module.symvers ");
	printf("\n");
	
	printf("cat -n /proc/kallsyms | grep --color \"devone\" \n");
	system("cat -n /proc/kallsyms | grep --color \"devone\" ");
	printf("\n");

	return;
}

#endif
