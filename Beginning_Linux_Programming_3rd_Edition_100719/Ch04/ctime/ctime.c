#include <stdio.h>
#include <time.h>
#include <string.h>

int 
main()
{
	time_t timeval;

	(void)time(&timeval);
	printf("The date is: %s", ctime(&timeval));

	return 0;
}

/*
int 
main()
{
	time_t tTemp;

	time(&tTemp);
	printf("@_: time(_tTemp) = %ld \n", (long)time(&tTemp));
	printf("%s", ctime(&tTemp));

	return 0;
}
*/
