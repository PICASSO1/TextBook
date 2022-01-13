#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a[] = "1000000000";
	char b[] = "1000000000";
	char c[] = "FFFF";

	printf("a = %d \n", strtol(a, NULL, 0));
	printf("b = %d \n", strtol(b, NULL, 2));
	printf("c = %d \n", strtol(c, NULL, 16));

	return 0;
}
