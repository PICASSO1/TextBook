#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: memory3.c
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

#define	ONE_K	1024

int 
main()
{
	char *some_memory = (char *)NULL;
	size_t size_to_allocate = (size_t)ONE_K;
	int megs_obtained = 0, ks_obtained = 0;

	while (1) {
		for (ks_obtained = 0; ks_obtained < ONE_K; ks_obtained++) {
			some_memory = (char *)malloc(sizeof(char) * size_to_allocate);
			if (some_memory == (char *)NULL)
				exit(EXIT_FAILURE);
			sprintf(some_memory, "Hello!! World!!");
		}
		megs_obtained++;
		printf("Now allocated %d Megabytes. \n", megs_obtained);
	}
	free((void *)some_memory);

	return EXIT_SUCCESS;
}
