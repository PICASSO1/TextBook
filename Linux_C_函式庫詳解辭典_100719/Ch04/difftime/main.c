#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
	time_t tTemp1, tTemp2;
	int a = 0, b = 0;
	double dSeconds = 0;

//	memset(&tTemp1, 0, sizeof(time_t));
	time(&tTemp1);
	printf("1. %s", ctime(&tTemp1));

	for(a = 0; a < 10000; a++)
		for(b = 0; b < 10000; b++)

//	memset(&tTemp2, 0, sizeof(time_t));
	time(&tTemp2);
	printf("2. %s", ctime(&tTemp2));

	dSeconds = difftime(tTemp1, tTemp2);
	printf("difftime() = %f \n", dSeconds);

	return 0;
}
