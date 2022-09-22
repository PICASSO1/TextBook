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
 * Description: 寫一個開平方根的函式。
 *
(*)?*/

#include <stdio.h>
#include <math.h>

void main(void)
{
	size_t idx = 0U;

	for (idx = 0; idx <= 10; idx++)
		printf("The square root of %.0f is %.0f \n", pow(idx, 2), sqrt(pow(idx, 2)));

	return;
}
