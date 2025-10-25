#include <stdio.h>

#define SQUARE(X) X*X
#define PR(X) printf("The result is %d. \n", X)

int main(void)
{
    int x=4, z=0;

	z=SQUARE(x);      // z=16;
	PR(z);      // The result is 16.
	z=SQUARE(2);      // z=4;
	PR(z);      // The result is 4.
	PR(SQUARE(x+2));      // 4+2*4+2 = 4+8+2 = 14;
	PR(100/SQUARE(2));      // 100/2*2 = 50*2 = 100;
	fprintf(stdout, "X is %d. \n", x);      // x=4;
	PR(SQUARE(++x));      // (++x)*(++x) = 5*6 = 30;
	fprintf(stdout, "After incrementing, x is %x. \n", x);      // x=6;

	return 0;
}
// 結論：不要在巨集定義中使用遞增(減)運算子!!