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
*	1. In /usr/include/stdio.h, defined P_tmpdir	"/tmp"
*/

int 
main()
{
	FILE *fp = (FILE *)NULL;

	fp = tmpfile();
	if (fp == NULL) {
		perror("tmpfile");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	
	return 0;
}
