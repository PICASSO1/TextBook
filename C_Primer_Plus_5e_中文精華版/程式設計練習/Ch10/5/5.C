#include <stdio.h>
#include <string.h>

double FunC(double arr[], int n);

int main(void)
{
	int a, nNum=0;
	double dResult=0.000000;
	double dArray[80];

	memset(dArray, 0, sizeof(dArray));

    puts("請問要輸入幾個浮點數(80個以內): ");
	while(scanf("%d", &nNum)==1)
	{
		printf("請輸入%d個浮點數: \n", nNum);
	    for(a=0; a<nNum; a++)
			scanf("%lf", &dArray[a]);
		dResult=FunC(dArray, nNum);
		printf("您所輸入的%d個浮點數中，極大與極小的差為: %lf \n\n", nNum, dResult);
		puts("請問要輸入幾個浮點數(80個以內): ");
	}

	return 0;
}
//===================================================================
double FunC(double arr[], int n)
{
	int a;
    double dMax=arr[0], dMin=arr[0], dResult=0.000000;

	for(a=0; a<n; a++)
	{
	    if(arr[a]>dMax)
			dMax=arr[a];
	}
	for(a=0; a<n; a++)
	{
	    if(arr[a]<dMin)
			dMin=arr[a];
	}
	dResult=dMax-dMin;

	return dResult;
}
