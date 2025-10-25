#include <stdio.h>
// #define JUST_CHECKING      // 隨便定義一個東西!!
#define LIMIT 4

int main(void)
{
    int i, total=0;
	for(i=1; i<=LIMIT; i++)
	{
	    total+=2*i*i+1;
#ifdef JUST_CHECKING
		fprintf(stdout, "i=%d, running total = %d \n", i, total);
#else
		fprintf(stdout, "我沒有被定義!! \n");
#endif
	}
    fprintf(stdout, "Grand total = %d \n", total);

	return 0;
}