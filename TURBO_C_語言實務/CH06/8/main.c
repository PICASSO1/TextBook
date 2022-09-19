/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091922
 *
 * Date: 2022 / 09 / 19
 *
 * Description: 試寫出下列程式的執行結果：
 *
(*)?*/

#include <stdio.h>

void main(void)
{
	unsigned int i = 0U;

	for (i = 100; i > 0; i /= 2)
		printf("%d \n", i);

	return;
}
