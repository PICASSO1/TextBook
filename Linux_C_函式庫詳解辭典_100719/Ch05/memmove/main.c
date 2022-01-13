#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[30] = "string(a)";
	char b[30] = "string\0string";
	int i = -9;

	strcpy(a, b);
	printf("strcpy(): ");
	for (i = 0; i < 30; i++)
		printf("%c ", a[i]);

	memmove((void *)a, (void *)b, 30);
	printf("\nmemmove(): ");
	for (i = 0; i < 30; i++)
		printf("%c ", a[i]);

	return 0;
}
