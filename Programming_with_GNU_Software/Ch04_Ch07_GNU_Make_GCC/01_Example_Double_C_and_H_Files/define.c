#include "./define.h"

int hhhh(int *x, int *y)
{
	return (*x + *y);
}

void test(void *DATA)
{
	data_t *yourData = (data_t *)DATA;

//	printf("(data_t *)DATA->abc = %d \n", *(yourData->abc));
	printf("(data_t *)DATA->abc = %d \n", *(((data_t *)DATA)->abc));
	*(((data_t *)DATA)->abc) = 9;

	return;
}
