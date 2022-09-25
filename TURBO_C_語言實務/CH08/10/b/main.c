/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092522
 *
 * Date: 2022 / 09 / 25
 *
 * Description: 以 ima(); 寫一個計算２ｘ２矩陣相乘之函式 ama(); 如 ama(a, b, c); 會把ａ與ｂ矩陣相乘，結果存入ｃ矩陣。
 *
(*)?*/

#include <stdio.h>

#define	NUM		2
#define	SIZE		2

void ama(int[][SIZE], int [][SIZE], int[][SIZE]);

void main(void)
{
	int a[SIZE][SIZE] = {
		{0x07, 0x08}, {0x09, 0x0A}		/* 7, 8, 9, 10 */
	}, b[SIZE][SIZE] = {
		{0x0B, 0x0C}, {0x0D, 0x0E}	/* 11, 12, 13, 14 */
	}, c[SIZE][SIZE] = {
		{0x00, 0x00}, {0x00, 0x00}		/* Result must be: 77, 96, 117, 140 */
	}, m = -1, n = -1;

	ama(a, b, c);
	for (m = 0; m < SIZE; m++) {
		for (n = 0; n < SIZE; n++)
			printf("c[%d][%d] = %d \n", m, n, *(*(c + m) + n));
	}

    return;
}

void 
ama(A, B, C)
int A[][SIZE], B[][SIZE], C[][SIZE];
{
	int p = -1, q = -1;

	for (p = 0; p < SIZE; p++) {
		for (q = 0; q < SIZE; q++)
			*(*(C + p) + q) = *(*(A + p) + q) * *(*(B + p) + q);
	}

	return;
}
