#include <stdio.h>
#include <string.h>

void Total(int Arry1[], int Arry2[], int Arry3[]);

int main(void)
{
	int a;
    int n1stArray[4]={2, 4, 5, 8};
	int n2ndArray[4]={1, 0, 4, 6};
	int n3rdArray[4];

	memset(n3rdArray, 0, sizeof(n3rdArray));

	puts("原本的陣列內容: ");
	printf("第一個陣列: ");
	for(a=0; a<4; a++)
		printf("%d ", n1stArray[a]);
	putc('\n', stdout);
	printf("第二個陣列: ");
	for(a=0; a<4; a++)
		printf("%d ", n2ndArray[a]);
	putchar('\n');
	Total(n1stArray, n2ndArray, n3rdArray);
	printf("最後的結果: ");
	for(a=0; a<4; a++)
		printf("%d ", n3rdArray[a]);
	putchar('\n');

	return 0;
}
//======================================================================
void Total(int Arry1[], int Arry2[], int Arry3[])
{
    int a;

	for(a=0; a<4; a++)
		Arry3[a]=Arry1[a]+Arry2[a];

	return;
}
