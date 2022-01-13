#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
	time_t tTemp;

	time(&tTemp);
	printf("@_: time(_tTemp) = %ld \n", (long)time(&tTemp));
	printf("%s", ctime(&tTemp));

	return 0;
}
