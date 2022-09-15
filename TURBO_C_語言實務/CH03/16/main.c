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
 * Description: 寫一程式計算 1 到 99 的奇整數和。
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	unsigned int sum = 0U, i = 0U;

	for (i = 1; i <= 99; i++) {
		if ((i % 2) != 0)
			sum += i;
	}
	printf("1 + 3 + 5 + .... + 97 + 99 = %d \n", sum);

	return 0;
}
