/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091822
 *
 * Date: 2022 / 09 / 18
 *
 * Description: 寫一函式 myputs(); 模擬 puts(); ，函式中只能用 putchar(); 。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t myputs(char *);

int main(void)
{
	myputs("Hello!! World!! ");

	return 0;
}

size_t myputs(char *str)
{
	size_t len = strlen(str), idx = 0U, size = 0U;

	for (idx = 0; idx < len; idx++) {
		putchar(*(str + idx));
		size++;
	}

	return size;
}
