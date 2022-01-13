#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t *_tTemp = (time_t *)NULL;

	time(_tTemp);
	printf("time(_tTemp) = %ld \n", (long)time(_tTemp));

	return 0;
}
