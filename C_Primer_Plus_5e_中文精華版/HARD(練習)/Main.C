// 這支程式的目的，是在示範如何將一個陣列，再儲存在另一個陣列中!!
#include <stdio.h>
#define SIZE1 2     // 三維陣列中，第一維的維度
#define SIZE2 3     // 三維陣列中，第二維的維度
#define SIZE3 4     // 三維陣列中，第三維的維度

int main(int argc, char *argv[], char *envp[])
{
	int i = 0, j = 0, k = 0;
//	這是第一個範例，這是基本的，簡單吧!!
/*	int a = 5, b = 6;
	int *pC = &a, *pD = &b;
	int *Array[2] = {pC, pD};

	printf("Array[0] = %d \n", *Array[0]);
	printf("Array[1] = %d \n", *Array[1]);
*/
//	第二個範例：這是宣告一個指標陣列，裡面再儲存一個一維陣列!!
/*	int a[3] = {1, 2, 3}, b[3] = {4, 5, 6};
	int *pC = a, *pD = b;
	int *Array[2] = {pC, pD};

	for(i=0; i<2; i++)
	{
		for(j=0; j<3;j++)
			printf("Array[%d][%d] = %d \n", i, j, *Array[i] + j);
	}
*/
//	第三個範例，應該是你要的吧!!
	int a[SIZE2][SIZE3] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
	int b[SIZE2][SIZE3] = {{12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}};
	int *pC = *a, *pD = *b;
	int *Array[SIZE1] = {pC, pD};
//  In otherwise：Array[SIZE1][SIZE2][SIZE3] == Array[2][3][4];
//	Array = {{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}},
//           {{12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}}};

	for(i=0; i<SIZE1; i++)      // 列印第一維的內容
	{
		for(j=0; j<SIZE2; j++)      // 列印第二維的內容
		{
			for(k=0; k<SIZE3; k++)      // 列印第三維的內容
				printf("Array[%d][%d][%d] = %d \n", i, j, k, (*Array[i] + SIZE3*j) + k);
		}
	}
	printf("Array[%d][%d][%d] = %d \n", i, j, k, (Array[1] + 2)[3]); // 17??

	return 0;
}
