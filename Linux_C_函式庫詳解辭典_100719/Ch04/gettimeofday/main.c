#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	struct timeval stTimeVal;
	struct timezone stTimeZone;

	memset(&stTimeVal, 0, sizeof(struct timeval));
	memset(&stTimeZone, 0, sizeof(struct timezone));
	gettimeofday(&stTimeVal, &stTimeZone);
	printf("stTimeVal.tv_sec = %ld \n", stTimeVal.tv_sec);
	printf("stTimeVal.tv_usec = %ld \n", stTimeVal.tv_usec);
	printf("stTimeZone.tz_minuteswest = %d \n", stTimeZone.tz_minuteswest);
	printf("stTimeZone.tz_dsttime = %d \n", stTimeZone.tz_dsttime);

	return 0;
}
/*
struct timeval
{
	long tv_sec;
	long tv_usec;
};

struct timezone
{
	int tz_minuteswest;
	int tz_dsttime;
};
*/
