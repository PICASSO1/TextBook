#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int nRet = -1;

	for (nRet = 0; nRet < 20; nRet++)
		printf("strerror(%d): %s \n", nRet, strerror(nRet));
	printf("%s: %d \n", __func__, __LINE__);

	return 0;
}
