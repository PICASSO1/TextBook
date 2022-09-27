/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092722
 *
 * Date: 2022 / 09 / 27
 *
 * Description: 寫一程式讀入任意整數算式如：２＋１３＊４－（５＋１２）＊３，並將其中的整數「運算元」排序印出。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

static const char *example = "2 + 13 * 4 - (5 + 12) * 3";

int main(void)
{
	size_t len = strlen(example), idx = 0U;
	char temp[64], *ptr = (char *)NULL, *saveptr = (char *)NULL;

	memset(temp, '\0', sizeof(char) * 64);
	for (idx = 0; idx < len; idx++) {
		if (*(example + idx) < '0' || *(example + idx) > '9')
			temp[idx] = ' ';
		else
			temp[idx] = *(example + idx); 
	}
	printf("The native data is       : %s \n", example);

	printf("The operands are in order: ");
	ptr = strtok_r(temp, " ", &saveptr);
	do {
		printf("%s ", ptr);
		ptr = strtok_r((char *)NULL, " ", &saveptr);
	} while (ptr != (char *)NULL);
	puts("");
	
	return 0;
}
