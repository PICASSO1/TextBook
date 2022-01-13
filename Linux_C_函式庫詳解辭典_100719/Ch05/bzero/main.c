#include <stdio.h>
#include <string.h>
// Please use "memset()" function instead of "bzero()"!!
// void bzero(void *s, int n)
int main(void)
{
	char strTemp[10];
	
	bzero((void *)strTemp, 10);
	printf("strTemp[10] = %s \n", strTemp);
	if (strcmp(strTemp, "\0") == 0) {
		memset(strTemp, 'A', sizeof(char) * 10);
		printf("strTemp[10] = %s \n", strTemp);
	}

	return 0;
}
