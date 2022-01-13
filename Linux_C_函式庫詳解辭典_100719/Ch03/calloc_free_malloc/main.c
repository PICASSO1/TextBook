#include <stdio.h>
#include <stdlib.h>

typedef struct test {
	int a[10];
	char b[20];
} TEST;

int main(void)
{
	TEST *ptr = NULL;

	ptr = (TEST *)calloc(sizeof(TEST), 10);
//	ptr = (TEST *)malloc(sizeof(TEST) * 10);
	printf("a[1] = %d \n", ptr->a[1]);

	ptr += sizeof(TEST);
	printf("b[2] = %d \n", ptr->b[2]);

	return 0;
}
