#include <stdio.h>
#include <stdlib.h>

int 
main()
{
	printf("Running \"ps -aux\" with system. \n");
	system("ps -aux");
/*	system("ps -aux &"); */
	printf("DONE. \n");

	return 0;
}
