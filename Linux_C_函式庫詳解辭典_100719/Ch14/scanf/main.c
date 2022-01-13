#include <stdio.h>

int main(void)
{
	int i = -1, nRcv = 9;
	unsigned int j = 8;
	char s[5];
	nRcv = fscanf(stdin, "%d %x %5[a-z] %*s %f", &i, &j, s, s);
	printf("%d %d %s; nRcv = %d \n", i, j, s, nRcv);

	return 0;
}
