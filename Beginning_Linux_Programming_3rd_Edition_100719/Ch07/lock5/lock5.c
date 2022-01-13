#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <errno.h>
#include <string.h>

/*
*	File Name: lock5.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030916
*
*	Date: 2016 / 03 / 09
*
*	Description: struct flock was defined in /usr/include/bits/fcntl.h
*	1. struct flock {
*		short int l_type;
*		short int l_whence;
*		__off_t l_start;	// long int
*		__off_t l_len;	// long int
*		__pid_t l_pid;	// int
*	};
*/

const char *test_file = "/var/tmp/test.lck";

int 
main()
{
	int file_desc = 0, res = 0;
	struct flock region_to_lock;

	file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
	if (file_desc == 0) {
		fprintf(stderr, "Unable to open %s for read / write. \n", test_file);
		exit(EXIT_FAILURE);
	}

	bzero((void *)&region_to_lock, sizeof(struct flock));
	region_to_lock.l_type = F_RDLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 10;
	region_to_lock.l_len = 5;
	printf("Process %d, trying F_RDLCK, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLK, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	region_to_lock.l_type = F_UNLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 10;
	region_to_lock.l_len = 5;
	printf("Process %d, trying F_UNLCK, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLK, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	region_to_lock.l_type = F_UNLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 0;
	region_to_lock.l_len = 50;
	printf("Process %d, trying F_UNLCK, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLK, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	region_to_lock.l_type = F_WRLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 16;
	region_to_lock.l_len = 5;
	printf("Process %d, trying F_WRLCK, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLK, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	region_to_lock.l_type = F_RDLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 40;
	region_to_lock.l_len = 10;
	printf("Process %d, trying F_RDLCK, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLK, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	region_to_lock.l_type = F_WRLCK;
	region_to_lock.l_whence = SEEK_SET;
	region_to_lock.l_start = 16;
	region_to_lock.l_len = 5;
	printf("Process %d, trying F_WRLCK with wait, region %ld to %ld. \n", (int)getpid(), \
		(long)region_to_lock.l_start, (long)(region_to_lock.l_start + region_to_lock.l_len));

	res = fcntl(file_desc, F_SETLKW, &region_to_lock);
	printf("Process %d - %s to lock region. \n", (int)getpid(), (res == -1)? "failed": "obtained");

	printf("Process %d ending!! \n", (int)getpid());
	close(file_desc);

	return 0;
}
