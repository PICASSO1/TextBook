#include <stdio.h>

#define XNAME(n) X##n
#define PRINT_XN(n) printf("X "#n" = %d. \n", X##n);

int main(void)
{
    int XNAME(1)=14;      // X1 = 14;
	int XNAME(2)=20;      // X2 = 20;

    PRINT_XN(1);      // X 1 = 14;
	PRINT_XN(2);      // X 2 = 20;

	return 0;
}