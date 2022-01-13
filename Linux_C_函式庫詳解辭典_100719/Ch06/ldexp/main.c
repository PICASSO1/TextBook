#include <stdio.h>
#include <math.h>

int main(void)
{
	int exp = 4;
	double x = 6, answer = 3;

	answer = ldexp(x, exp);
	printf("%f * 2 ^ (%d) = %f \n", x, exp, answer);

	return 0;
}
