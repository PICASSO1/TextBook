#include <stdio.h>

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
	FILE *fp = (FILE *)NULL;
	int fd = 0;

	fp = fopen("/dev/tty", "r");
	fd = fileno(fp);
	printf("fileno(fp) = %d \n", fd);
	fclose(fp);

	return 0;
}
