#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
	clock_t nRet = (clock_t)6;

	nRet = clock();
	printf("clock() = %d \n", (int)nRet);

	return 0;
}
