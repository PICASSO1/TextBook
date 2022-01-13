#include <stdio.h>
#include <math.h>
#include <assert.h>

double 
my_sqrt(x)
double x;
{
	assert(x >= 0.0);
	return sqrt(x);
}

int 
main(void)
{
	printf("sqrt + 2 = %g \n", my_sqrt(2.0));
	printf("sqrt - 2 = %g \n", my_sqrt(-2.0));

	return 0;
}
