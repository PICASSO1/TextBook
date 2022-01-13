#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <errno.h>

/*
*	File Name: lock2.c
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

const char *lock_file = "/var/tmp/LCK.test2";

int 
main()
{
	int file_desc = 0;
	int tires = 10;

	while (tires--) {
		file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);
		if (file_desc == -1) {
			printf("%d - Lock already present. \n", getpid());
			sleep(3);
		}
		else {
			printf("%d - I have exclusive access. \n", getpid());
			sleep(1);
			close(file_desc);
			unlink(lock_file);
			sleep(2);
		}
	}

	return 0;
}
