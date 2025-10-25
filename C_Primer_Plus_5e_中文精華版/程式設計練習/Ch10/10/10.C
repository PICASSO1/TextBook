#include <stdio.h>
#include <string.h>

void Show(long ARRY[][5], int n);
void Count(long ARRY[][5], int n);

int main(void)
{
    long lArray[3][5]={{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}};

	puts("原本lArray[3][5]的陣列內容: ");
	Show(lArray, 3);
	Count(lArray, 3);
	puts("加倍過的陣列內容: ");
	Show(lArray, 3);
	putchar('\n');

	return 0;
}
//=================================================================================
void Show(long ARRY[][5], int n)
{
	int a, b;

    for(a=0; a<n; a++)
	{
	    for(b=0; b<5; b++)
			printf("%d ", ARRY[a][b]);
		putchar('\n');
	}

	return;
}
//==================================================================================
void Count(long ARRY[][5], int n)
{
	int a, b;

    for(a=0; a<n; a++)
	{
	    for(b=0; b<5; b++)
			ARRY[a][b]*=2;
	}

	return;
}
