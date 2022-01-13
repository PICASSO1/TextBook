#include <stdio.h>
#include <unistd.h>

/*
*	File Name: memory5b.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030816
*
*	Date: 2016 / 03 / 08
*
*	Description: 
*	1. 
*/

int 
main()
{
	char z = *(const char *)NULL;

	printf("I read from location zero. \n");

	return 0;
}
