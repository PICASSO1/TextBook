#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: memory6.c
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

#define	ONE_K	1024

int 
main()
{
	char *some_memory = (char *)NULL;

	some_memory = (char *)malloc(sizeof(char) * ONE_K);
	if (some_memory != (char *)NULL) {
		free((void *)some_memory);
		return 0;
	}

	return 0;
}
