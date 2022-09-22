/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092222
 *
 * Date: 2022 / 09 / 22
 *
 * Description: 假設：
 *       double a[4] = {10, 0, 20, 0, 30, 40, 0};
 *       double *pa = &a[1], **ppa = &pa;
 *       int i = 4;
 *
 *       已知 pa = 160，ppa 為 280，請回答下列各式的值：
 *
 *       a. pa[3]
 *       b. pa + 2
 *       c. pa + i
 *       d. ppa + i
 *       e. *pa + i
 *       f. *(pa + 2)
 *       g. *ppa
 *       h. **ppa + 1
 *       i. *ppa + 1
 *       j. *(*ppa + 1)
 *
(*)?*/

#include <stdio.h>

void Usage(void)
{
	printf("double a[4] = {10, 0, 20, 0, 30, 40, 0}; \n");
	printf("double *pa = &a[1]; \n");
	printf("double **ppa = &pa; \n");
	printf("int i = 4; \n");
	printf("NOTE: sizeof(double) = %zu \n", sizeof(double));
	printf("\n");

	return;
}

void main(void)
{
	double a[4] = {10, 0, 20, 0, 30, 40, 0};
	double *pa = &a[1];		/* 把陣列 a[1] 的記憶體位址，設給 pa；即 pa 指標是指到一個 double 的資料型態 */
	double **ppa = &pa;		/* 再把儲存 pa 的記憶體位址，設給 ppa */
	int i = 4;

	Usage();
	printf("0). a[0]        : %2.0f (%p) \n", a[0], &a[0]);
	printf("1). a[1]        : %2.0f (%p) \n", a[1], &a[1]);
	printf("2). a[2]        : %2.0f (%p) \n", a[2], &a[2]);
	printf("3). a[3]        : %2.0f (%p) \n", a[3], &a[3]);
	/* 因為 a 的大小只有 4 ，所以 index 4 ~ 6 都會是 Dirty Value. */
	printf("4). a[4]        : %f (%p) \n", a[4], &a[4]);
	printf("5). a[5]        : %f (%p) \n", a[5], &a[5]);
	printf("6). a[6]        : %f (%p) \n", a[6], &a[6]);
	printf("\n");
	printf("a). pa[3]       : %2.0f (%p) \n", pa[3], &pa[3]);
	/* pa[3] 的值和記憶體位址，應該等同於 a[4] */
	printf("b). pa + 2      : %2.0f (%p) \n", pa + 2, pa + 2);
	/* 因為 pa 是指到一個 double 的資料型態，所以再 +2 ，即 sizeof(double) * 2 。記憶體位址和值應該等同於 a[3] */
	printf("c). pa + i      : %2.0f (%p) \n", pa + i, pa + i);
	/* i = 4 ，原理同 b). 記憶體位址和值應該等同於 a[5] ；是個 Dirty Value. */
	printf("d). ppa + i     : %2.0f (%p) \n", ppa + i, ppa + i);
	/* 不知該如何解讀！ */
	printf("e). *pa + i     : %2.0f (%p) \n", *pa + i, *pa + i);
	/* *pa == a[1] == 0 ； 0 + 4 = 4 */
	printf("f). *(pa + 2)   : %2.0f (%p) \n", *(pa + 2), pa + 2);
	/* 原理同 b). ；(pa + 2) 的記憶體位址等同於 a[3] ，其值為 0 */
	printf("g). *ppa        : %2.0f (%p) \n", *ppa, *ppa);
	/* **ppa == &pa; *ppa == pa == &a[1]; *ppa 其值和記憶體位址，應該等同於 a[1] */
	printf("h). **ppa + 1   : %2.0f (%p) \n", **ppa + 1, **ppa + 1);
	/* 不知該如何解讀！ */
	printf("i). *ppa + 1    : %2.0f (%p) \n", *ppa + 1, *ppa + 1);
	/* 原理同 g). ，*ppa == pa == &a[1] == 0; 0 + 1 = 1 */
	printf("j). *(*ppa + 1) : %2.0f (%p) \n", *(*ppa + 1), *ppa + 1);
	/* 原理同 i). ，(*ppa + 1) == (pa + sizeof(double) * 1) == &a[2] == 20 */

	return;
}
