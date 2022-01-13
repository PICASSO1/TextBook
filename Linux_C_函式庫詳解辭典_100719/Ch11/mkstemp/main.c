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
	int nRet = -1;

	nRet = mkstemp(tempfile);
	if (nRet == -1) {
		perror("mkstemp");
		exit(EXIT_FAILURE);
	}
	printf("mkstemp(): %s \n", tempfile);

	return 0;
}
