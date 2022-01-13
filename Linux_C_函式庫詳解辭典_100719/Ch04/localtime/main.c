#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
	time_t tTemp;
	struct tm *pstTm = NULL;

	memset(&tTemp, 0, sizeof(time_t));
	time(&tTemp);
	printf("@_: time(_tTemp) = %ld \n", (long)time(&tTemp));
	pstTm = localtime(&tTemp);
	printf("pstTm->tm_year = %d \n", pstTm->tm_year + 1900);
	printf("pstTm->tm_mon = %d \n", pstTm->tm_mon + 1);
	printf("pstTm->tm_mday = %d \n", pstTm->tm_mday);
	printf("pstTm->tm_wday = %d \n", pstTm->tm_wday);
	printf("pstTm->tm_hour = %d \n", pstTm->tm_hour);
	printf("pstTm->tm_min = %d \n", pstTm->tm_min);
	printf("pstTm->tm_sec = %d \n", pstTm->tm_sec);

	return 0;
}
