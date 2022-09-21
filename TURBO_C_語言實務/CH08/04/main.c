/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092122
 *
 * Date: 2022 / 09 / 21
 *
 * Description: 回答下面程式執行的結果為何？
 *
(*)?*/

#include <stdio.h>

void main(void)
{
	int c[15][15], *a[10], (*b)[15], i, j;

	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
			c[i][j] = i * 3 + j;

	b = c;
	printf("(*b++)[0] = %d \n", (*b++)[0]);
	printf("b[3][4] = %d \n", b[3][4]);
	printf("(*++b)[10] = %d \n", (*++b)[10]);

	for (i = 0; i < 10; i++)
		a[i] = &c[15 - i][0];

	printf("a[3][6] = %d \n", a[3][6]);
	printf("*a[5] = %d \n", *a[5]);

	return;
}
