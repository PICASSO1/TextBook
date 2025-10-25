#include <stdio.h>

int count=0;                          // 宣告一個全域變數
void report_count();
void accumulate(int k);

int main(void)
{
    int value;
	register int i;                   // 宣告一個暫存器變數

	printf("Enter a positive interge (0 to quit): ");
	while(scanf("%d",&value)==1 && value>0)
	{
	    ++count;
		for(i=value;i>=0;i--)
		    accumulate(i);
		printf("Enter a positive interge (0 to quit): ");
	}
	report_count();

	return 0;
}
//==========================================================
void report_count()
{
    printf("Loop executed %d times \n", count);
}
