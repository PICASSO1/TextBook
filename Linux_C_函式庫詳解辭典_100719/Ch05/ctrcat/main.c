#include <stdio.h>
#include <string.h>

#define	SIZE	9

int main(void)
{
	int i = -1;
	char cArray[SIZE];

	memset(&cArray, 'A', sizeof(char) * SIZE);
	for (i = 0; i < 9; i++)
		printf("cArray[%d] = %c \n", i, cArray[i]);

	return 0;
}
