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
 * Description: 寫一函式ｇ(ｆ, ｎ);ｎ為任意１０進制整數，ｆ為'ｂ'、'ｏ'、'ｘ'字元之一，ｂ表２進制，ｏ表８進制，ｘ表１６進制。ｇ(ｆ, ｎ); 把ｎ轉換成ｆ指定之數制，並以字串之形式傳回。
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE	128

char *g_str = (char *)NULL;

size_t isInteger(char *);
char *byte_to_binary(int);
char *g(char, int);

void main(void)
{
	char integer[SIZE];

	memset(integer, '\0', sizeof(char) * SIZE);
	fprintf(stdout, "Please input an integer: ");
	while (fscanf(stdin, "%s", integer) == 1) {
		if (isInteger(integer) == 1) {
			fprintf(stderr, "Incorrect!! \n");
			memset(integer, '\0', sizeof(char) * SIZE);
			fprintf(stdout, "Please input an integer: ");
		}			
		else
			break;
	}
	puts("");
	printf("The \"%s\" Binary is     : %s \n", integer, g('b', atoi(integer)));
	printf("The \"%s\" Octal is      : %s \n", integer, g('o', atoi(integer)));
	printf("The \"%s\" Hexadecimal is: %s \n", integer, g('x', atoi(integer)));

	free((void *)g_str);

	return;
}

size_t 
isInteger(str)
char *str;
{
	size_t len = strlen(str), idx = 0U, flag = 0U;

	for (idx = 0; idx < len; idx++) {
		if (*(str + idx) < '0' || *(str + idx) > '9') {
			if (*(str + idx) != '-') {
				flag = 1;
				break;
			}
		}
	}

	return flag;
}

char *
byte_to_binary(x)
int x;
{
	int z = -1;
    static char b[64];

    memset(b, '\0', sizeof(char) * 64);
    for (z = 32768; z > 0; z >>= 1)
        strcat(b, ((x & z) == z)? "1": "0");

    return b;
}

char *
g(key, value)
char key; 
int value;
{
	g_str = (char *)malloc(sizeof(char) * SIZE);
	if (g_str == (char *)NULL) {
		perror("Allocated memory failed!! \n");
		exit(EXIT_FAILURE);
	}

	memset(g_str, '\0', sizeof(char) * SIZE);
	switch (key) {
		case 'b':
			strcpy(g_str, byte_to_binary(value));
			break;
		case 'o':
			sprintf(g_str, "%o", value);
			break;
		case 'x':
			sprintf(g_str, "%x", value);
			break;
		default:
			break;
	}

	return g_str;
}
