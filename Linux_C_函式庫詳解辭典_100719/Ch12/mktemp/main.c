#include <stdio.h>
#include <stdlib.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022516
*
*	Date: 2016 / 02 / 25
*
*	Description: 
*	1. 
*/

int 
main()
{
	char tempfile[] = "template-XXXXXX";
	char *ptr = (char *)NULL;

	ptr = mktemp(tempfile);
	if (ptr == (char *)NULL) {
		perror("mktemp");
		exit(EXIT_FAILURE);
	}
	printf("mktemp(): %s \n", tempfile);

	return 0;
}
