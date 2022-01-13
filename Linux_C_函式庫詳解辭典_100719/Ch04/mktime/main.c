#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	time_t TEMP1;
	struct tm *pTime = NULL;
	
	bzero((void *)&TEMP1, sizeof(time_t));

	time(&TEMP1);
	printf("time(&TEMP1) = %ld \n\n", (long)time(&TEMP1));

	pTime = localtime(&TEMP1);
	printf("pTime->tm_year = %d \n", pTime->tm_year + 1900);
	printf("pTime->tm_mon = %d \n", pTime->tm_mon + 1);
	printf("pTime->tm_mday = %d \n", pTime->tm_mday);
	printf("pTime->tm_wday = %d \n", pTime->tm_wday);
	printf("pTime->tm_hour = %d \n", pTime->tm_hour);
	printf("pTime->tm_min = %d \n", pTime->tm_min);
	printf("pTime->tm_sec = %d \n", pTime->tm_sec);
	puts("\0");

	TEMP1 = mktime(pTime);
	printf("time() -> localtime() -> mktime(): %ld \n", (long)TEMP1);

	return 0;
}
