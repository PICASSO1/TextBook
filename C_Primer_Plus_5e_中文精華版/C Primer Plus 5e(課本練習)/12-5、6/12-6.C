#include <stdio.h>

extern int count;              // 把σ郎﹚竡筁
static int total=0;            // 繰篈场硈挡把计度ノ郎

void accumulate(int k)
{
    static int subtotal=0;      // 繰篈ず场硈挡把计度ノㄧΑ
	if(k<=0)
    {
	    printf("loop cycle: %d \n", count);
		printf("subtotal: %d; total: %d \n", subtotal, total);
		subtotal=0;
	}
	else
	{
	    subtotal+=k;
		total+=k;
	}
}