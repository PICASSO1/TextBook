#include <stdio.h>

#define	_XOPEN_SOURCE
#include <time.h>
#include <string.h>

int 
main()
{
	struct tm *tm_ptr = (struct tm *)NULL, timestruct;
	time_t the_time;
	char buf[256], *result = (char *)NULL;

	bzero((void *)&the_time, sizeof(time_t));
	(void)time(&the_time);
	tm_ptr = localtime(&the_time);
	strftime(buf, sizeof(char) * 256, "%A %d %B, %I:%S %p", tm_ptr);

	printf("strftime gives: %s \n", buf);

	strcpy(buf, "Sat 26 July 2003, 17:53:32 will do fine. ");

	printf("Calling strptime with: %s \n", buf);
	bzero((void *)&timestruct, sizeof(struct tm));
	tm_ptr = &timestruct;

	result = (char *)strptime(buf, "%a %d %b %Y, %H:%M:%S", tm_ptr);
	printf("strptime consumed up to: %s \n", result);
	printf("strptime gives: \n");
	printf("Date: %02d / %02d / %02d \n", tm_ptr->tm_year % 100, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
	printf("Time: %02d:%02d:%02d \n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

	return 0;
}
