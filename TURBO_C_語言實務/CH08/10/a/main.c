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
 * Description: 
 *
(*)?*/

#include <stdio.h>

#define	NUM		2
#define	SIZE		2

void ima(int, int [][SIZE]);

void main(void)
{
	int a[SIZE][SIZE] = {{3, 4}, {5, 6}}, x = -1, y = -1;

	ima(NUM, a);
	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++)
			printf("temp[%d][%d] = %d \n", x, y, a[x][y]);
	}

    return;
}

void 
ima(num, A)
int num, A[][SIZE];
{
	int i = -1, j = -1;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			A[i][j] *= num;
	}

	return;
}
