#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: memory1.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030716
*
*	Date: 2016 / 03 / 07
*
*	Description: 
*	1. 
*/

#define	A_MEGABYTE	(1024 * 1024)

int 
main()
{
	char *some_memory = (char *)NULL;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE;

	some_memory = (char *)malloc(sizeof(char) * megabyte);
	if (some_memory != (char *)NULL) {
		sprintf(some_memory, "Hello!! World!! \n");
		printf("%s ", some_memory);
		exit_code = EXIT_SUCCESS;
	}
	free((void *)some_memory);

	return exit_code;
}
