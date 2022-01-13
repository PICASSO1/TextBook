#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <errno.h>
#include <string.h>

/*
*	File Name: lock3.c
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

const char *test_file = "/var/tmp/test.lck";

int 
main()
{
	int file_desc = 0, byte_count = -1, res = 0;
	char *byte_to_write = "A";
	struct flock region_1, region_2;

	// Open a file description
	file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
	if (test_file == 0) {
		fprintf(stderr, "Unable to open %s for read / write. \n", test_file);
		exit(EXIT_FAILURE);
	}

	// Put some data to file
	for (byte_count = 0; byte_count < 100; byte_count++)
		write(file_desc, (void *)byte_to_write, 1);

	// 我們使用"共享鎖"，鎖定region_1，範圍為第10位元組 ~ 第30位元組
	bzero((void *)&region_1, sizeof(struct flock));
	region_1.l_type = F_RDLCK;
	region_1.l_whence = SEEK_SET;
	region_1.l_start = 10;
	region_1.l_len = 20;

	// 我們使用"獨占鎖"，鎖定region_2，範圍為第40位元組 ~ 第50位元組
	bzero((void *)&region_2, sizeof(struct flock));
	region_2.l_type = F_WRLCK;
	region_2.l_whence = SEEK_SET;
	region_2.l_start = 40;
	region_2.l_len = 10;

	// 現在，鎖定檔案中的區域....
	printf("Process %d locking file. \n", (int)getpid());
	res = fcntl(file_desc, F_SETLK, &region_1);
	if (res == -1)
		fprintf(stderr, "Failed to lock \"region_1\"!! \n");
	res = fcntl(file_desc, F_SETLK, &region_2);
	if (res == -1)
		fprintf(stderr, "Failed to lock \"region_2\"!! \n");
	// 稍等一下
	sleep(60);

	printf("Process %d closing file. \n", (int)getpid());
	close(file_desc);

	return 0;
}
