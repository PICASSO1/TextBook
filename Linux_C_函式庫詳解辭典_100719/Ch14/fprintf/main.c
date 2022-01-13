#include <stdio.h>

int main(void)
{
	int i = 150, j = -100, nRcv0 = -1, nRcv1 = -2;
	double k = 3.14159;

	nRcv0 = fprintf(stdout, "%d %f %x \n", j, k, i);
	nRcv1 = fprintf(stderr, "%2d %*d \n", i, 2, i);
	fprintf(stdout, "nRcv0 = %d; nRcv1 = %d \n", nRcv0, nRcv1);

	return 0;
}
