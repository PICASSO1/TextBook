#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int 
main()
{
	int i = 0;
	time_t the_time;

	bzero(&the_time, sizeof(time_t));
	for (i = 1; i <= 10; i++) {
		the_time = time((time_t *)0);
		printf("The time is %ld \n", the_time);
		sleep(2);
	}

	return 0;
}

/*
int 
main()
{
	time_t *_tTemp = (time_t *)NULL;

	time(_tTemp);
	printf("time(_tTemp) = %ld \n", (long)time(_tTemp));

	return 0;
}
*/
