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
 * Description: 寫一程式印出從 9 到 234 之間 (含 9 與 234) 9 的倍數。
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	unsigned int i = 0U;

	for (i = 9; i <= 234; i++) {
		if ( i % 9 == 0)
			printf("i = %d \n", i);
	}

	return 0;
}
