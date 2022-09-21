/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092122
 *
 * Date: 2022 / 09 / 21
 *
 * Description: 寫一程式把下列陣列各元素印出：
 *     a. int a[] = {1, 2, 3, 4, 5};
 *     b. char b[] = "This is an array. ";
 *     c. char c[][] = {"This is a cat. ", "That is a dog. "};
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE_A	5
#define	SIZE_C	2

void main(void)
{
	int *a = (int *)NULL;
	char b[] = "This is an array. ";
	char *c[] = {"This is a cat. ", "That is a dog. "};
	size_t x = 0, y = 0, len = 0;

	/* a. int a[] = {1, 2, 3, 4, 5}; */
	a = (int *)malloc(sizeof(int) * SIZE_A);
	if (a == (int *)NULL) {
		perror("Allocate memory failed!! \n");
		exit(EXIT_FAILURE);
	}

	for (x = 0; x < SIZE_A; x++)
		*(a + x) = x + 1;

	for (x = 0; x < SIZE_A; x++)
		printf("a[%zu] = %d \n", x, *(a + x));

	/* b. char b[] = "This is an array. "; */
	puts("");
	len = strlen(b);
	for (x = 0; x < len; x++)
		printf("b[%zu] = %c \n", x, *(b + x));

	/* c. char c[][] = {"This is a cat. ", "That is a dog. "}; */
	puts("");
	for (x = 0; x < SIZE_C; x++) {
		len = strlen(*(c + x));
		for (y = 0; y < len;y++)
			printf("c[%zu][%zu]: %c \n", x, y, *(*(c + x) + y));
	}

	free((void *)a);

    return;
}
