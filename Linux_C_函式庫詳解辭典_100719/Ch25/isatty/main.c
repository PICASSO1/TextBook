#include <stdio.h>
#include <unistd.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022616
*
*	Date: 2016 / 02 / 26
*
*	Description: 
*	1. 
*/

int 
main()
{
	if (isatty(fileno(stdin)) != -1)
		printf("STDIN is not a terminal!! \n");

	if (isatty(fileno(stdout)) != -1)
		printf("STDOUT is not a terminal!! \n");

	if (isatty(fileno(stderr)) != -1)
		printf("STDERR is not a terminal!! \n");

	return 0;
}
