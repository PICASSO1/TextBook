/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092522
 *
 * Date: 2022 / 09 / 25
 *
 * Description: 
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE		32

const static char *a = "0123456789";
char *i2a(int);
char *g_ptr = (char *)NULL;

void main(void)
{
	printf("i2a(1234): %s \n", i2a(1234));
	free((void *)g_ptr);

    return;
}

char *
i2a(NUM)
int NUM;
{
	char strNum[SIZE];
	size_t r = 0U, s = 0U, len = 0U;

	g_ptr = (char *)malloc(sizeof(char) * SIZE);
	if (g_ptr == (char *)NULL) {
		fprintf(stderr, "Allocated memory failed!! \n");
		exit(EXIT_FAILURE);
	}

	memset(strNum, '\0', sizeof(char) * SIZE);
	memset(g_ptr, '\0', sizeof(char) * SIZE);
	sprintf(strNum, "%d", NUM);
	len = strlen(strNum);
	for (r = 0; r < len; r++) {
		for (s = 0; s < 10; s++) {
			if ((int)strNum[r] == *(a + s))
				*(g_ptr + r) = strNum[r];
		}
	}
	*(g_ptr + len) = '\0';

	return g_ptr;
}
