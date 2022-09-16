/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091522
 *
 * Date: 2022 / 09 / 15
 *
 * Description: 寫一程式印出九九乘法表。
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	unsigned int x = 0U, y = 0U;

	for (x = 1; x <= 9; x++) {
		for (y = 1; y <= 9; y++)
			printf("%d * %d = %d \n", x, y, x * y);

		printf("\n");
	}

	return 0;
}
