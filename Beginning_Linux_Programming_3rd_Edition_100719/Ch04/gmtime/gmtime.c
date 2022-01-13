#include <stdio.h>
#include <time.h>
#include <string.h>

int 
main()
{
	struct tm *tm_ptr = (struct tm *)NULL;
	time_t the_time;

	bzero(&the_time, sizeof(time_t));
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);

	printf("Raw time is %ld \n", the_time);
	printf("gmtime gives: \n");
	printf("Date: %02d / %02d / %02d \n", tm_ptr->tm_year, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
	printf("Time: %02d:%02d:%02d \n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

	return 0;
}

/*
int 
main()
{
	time_t tTemp;
	struct tm *pstTm = NULL;

	memset(&tTemp, 0, sizeof(time_t));
	time(&tTemp);
	printf("@_: time(_tTemp) = %ld \n", (long)time(&tTemp));
	pstTm = gmtime(&tTemp);
	printf("pstTm->tm_sec = %d \n", pstTm->tm_sec);
	printf("pstTm->tm_min = %d \n", pstTm->tm_min);
	printf("pstTm->tm_hour = %d \n", pstTm->tm_hour);
	printf("pstTm->tm_mday = %d \n", pstTm->tm_mday);
	printf("pstTm->tm_mon = %d \n", pstTm->tm_mon + 1);
	printf("pstTm->tm_year = %d \n", pstTm->tm_year + 1900);
	printf("pstTm->tm_wday = %d \n", pstTm->tm_wday);
	printf("pstTm->tm_yday = %d \n", pstTm->tm_yday);
	printf("pstTm->tm_isdst = %d \n", pstTm->tm_isdst);

	return 0;
}
*/
