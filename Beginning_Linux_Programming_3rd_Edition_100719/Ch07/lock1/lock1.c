#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <errno.h>

/*
*	File Name: lock1.c
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
	int file_desc = 0;
	int save_errno = 0;

	file_desc = open("/var/tmp/LCK.test", O_RDWR | O_CREAT | O_EXCL, 0444);
	if (file_desc == -1) {
		save_errno = errno;
		printf("Open failed with errno %d: %s \n", save_errno, strerror(save_errno));
	}
	else
		printf("Open successded!! \n");

	close(file_desc);

	return 0;
}
