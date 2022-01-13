#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 8, j = 4;

	for (i = 0; i < 10; i++) {
		j = 1 + (int)(10.0 * rand() / (RAND_MAX + 1.0));
		printf("%d ", j);
	}
	printf("\n");

	return 0;
}
