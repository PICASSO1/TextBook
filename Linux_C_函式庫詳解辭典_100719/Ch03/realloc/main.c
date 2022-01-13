#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build031416
*
*	Date: 2016 / 03 / 14
*
*	Description: 
*	1. 
*/

int 
main()
{
	char *ptr0 = (char *)NULL;
	char *ptr1 = (char *)NULL;
	char *ptr2 = (char *)NULL;

	ptr0 = (char *)malloc(sizeof(char) * 10);
	memset(ptr0, 'A', sizeof(char) * 10);
	*(ptr0 + 9) = '\0';
	printf("Before realloc(): ptr0 = %X [%s] \n", ptr0, ptr0);

	ptr1 = (char *)realloc(ptr0, sizeof(char) * 20);
	memset(ptr1, 'B', sizeof(char) * 20);
	*(ptr1 + 19) = '\0';
	printf("After realloc(): ptr1 = %X [%s] \n", ptr1, ptr1);

	ptr2 = (char *)realloc(ptr1, sizeof(char) * 5);
	memset(ptr2, 'C', sizeof(char) * 5);
	*(ptr2 + 4) = '\0';
	printf("After realloc() again: ptr2 = %X [%s] \n", ptr2, ptr2);

	return 0;
}
