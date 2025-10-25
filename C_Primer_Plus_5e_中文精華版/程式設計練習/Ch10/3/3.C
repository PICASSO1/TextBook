#include <stdio.h>
#include <string.h>

int Max(int arr[], int Size);

int main(void)
{
	int n, nMax=0, a=0;
    int arr[80];

	memset(arr, 0, sizeof(arr));

	puts("請問要輸入幾個整數(80個以內): ");
	while((scanf("%d", &a))==1)
	{
		printf("請輸入%d個數字: \n", a);
	    for(n=0; n<a; n++)
	        scanf("%d", &arr[n]);
	    nMax=Max(arr, a);
	    printf("剛剛所輸入的%d個數中，最大的是%d \n\n", a, nMax);
		puts("請問要輸入幾個整數(80個以內): ");
	}

	return 0;
}
//===================================================================
int Max(int arr[], int Size)
{
    int a, nMax=arr[0];

	for(a=0; a<Size; a++)
	{
	    if(arr[a]>nMax)
			nMax=arr[a];
	}

	return nMax;
}
