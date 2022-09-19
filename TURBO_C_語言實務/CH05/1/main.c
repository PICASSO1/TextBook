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
 * Description: 回答下列程式執行之結果：
 *
(*)?*/

#include <stdio.h>

void main(void)
{
	int a, b = 1, c = 1;

	a = (++b) + (++c);
	printf("%d %d %d \n", a, b, c);

	a = (b++) + (c++);
	printf("%d %d %d \n", a, b, c);

	a = (++b) + (c--);
	printf("%d %d %d \n", a, b, c);

	a = (b--) + (--c);
	printf("%d %d %d \n", a, b, c);

	return;
}
