#include <stdio.h>
#include <string.h>

int Max(double arr[], int Size);

int main(void)
{
	int n, nMax=0, a=0;
    double arr[80];

	memset(arr, 0, sizeof(arr));

	puts("請問要輸入幾個浮點數(80個以內): ");
	while((scanf("%d", &a))==1)
	{
		printf("請輸入%d個數字: \n", a);
	    for(n=0; n<a; n++)
	        scanf("%lf", &arr[n]);
	    nMax=Max(arr, a);
	    printf("剛剛所輸入的%d個數中，最大的是第%d個數 \n\n", a, nMax+1);
		puts("請問要輸入幾個浮點數(80個以內): ");
	}

	return 0;
}
//===================================================================
int Max(double arr[], int Size)
{
    int a, nIndex=0;
	double dMax=arr[0];

	for(a=0; a<Size; a++)
	{
	    if(arr[a]>dMax)
		{
			dMax=arr[a];
			nIndex=a;
		}
	}

	return nIndex;
}
