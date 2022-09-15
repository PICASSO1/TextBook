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
 * Description: 寫一程式印出 2 的 1 ~ 10 次方的值。
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	unsigned int i = 0U, sum = 1, base = 2;

	for (i = 1; i <= 10; i++) {
		printf("2 ^ %d = %d \n", i, base * sum);
		sum *= base;
	}

	return 0;
}
