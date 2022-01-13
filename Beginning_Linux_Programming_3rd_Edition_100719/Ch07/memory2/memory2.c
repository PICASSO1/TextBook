#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: memory2.c
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
#define	PHY_MEM_MEGS	256

int 
main()
{
	char *some_memory = (char *)NULL;
	size_t size_to_allocate = A_MEGABYTE;
	int megs_obtained = 0;

	while (megs_obtained < (PHY_MEM_MEGS * 2)) {
		some_memory = (char *)malloc(sizeof(char) * size_to_allocate);
		if (some_memory != (char *)NULL) {
			megs_obtained++;
			sprintf(some_memory, "Hello!! World!!");
			printf("%s - now allocated %d Megabytes \n", some_memory, megs_obtained);
		}
		else
			return 1;
	}
	free((void *)some_memory);

	return 0;
}
