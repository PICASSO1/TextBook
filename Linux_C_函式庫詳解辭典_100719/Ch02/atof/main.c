#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *a = "-100.23";
	char *b = "200e-2";
	float c = 0.101001;

	c = atof(a) + atof(b);
	printf("c = %.2f \n", c);

	return 0;
}
