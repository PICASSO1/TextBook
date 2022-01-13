#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a[] = "-100";
	char b[] = "  456";
	int c = 0;

	c = atoi(a) + atoi(b);
	printf("c = %d \n", c);

	return 0;
}
