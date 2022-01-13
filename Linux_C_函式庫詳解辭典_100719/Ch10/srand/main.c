#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i = 8, j = 4;

	srand((int)time(0));	// Here....@@
	for (i = 0; i < 10; i++) {
		j = 1 + (int)(10.0 * rand() / (RAND_MAX + 1.0));
		printf("%d ", j);
	}
	printf("\n");

	return 0;
}
