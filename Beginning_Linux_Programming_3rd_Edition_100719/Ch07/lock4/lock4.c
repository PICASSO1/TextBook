#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <errno.h>
#include <string.h>

/*
*	File Name: lock4.c
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

#define	SIZE_TO_TRY	5

void show_lock_info(struct flock *);

int 
main()
{
	int file_desc = 0, res = 0, start_byte = 0;
	struct flock region_to_test;	

	// Open a file description
	file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
	if (test_file == 0) {
		fprintf(stderr, "Unable to open %s for read / write. \n", test_file);
		exit(EXIT_FAILURE);
	}

	bzero((void *)&region_to_test, sizeof(struct flock));
	for (start_byte = 0; start_byte < 99; start_byte += SIZE_TO_TRY) {
		// 設定我們要檢查的區域
		region_to_test.l_type = F_WRLCK;
		region_to_test.l_whence = SEEK_SET;
		region_to_test.l_start = start_byte;
		region_to_test.l_len = SIZE_TO_TRY;
		region_to_test.l_pid = -1;

		printf("Testing F_WRLCK on region from %d to %d. \n", start_byte, start_byte + SIZE_TO_TRY);

		// 現在檢查檔案的鎖
		res = fcntl(file_desc, F_GETLK, &region_to_test);
		if (res == -1) {
			fprintf(stderr, "F_GETLK failed!! \n");
			exit(EXIT_FAILURE);
		}
		if (region_to_test.l_pid != -1) {
			printf("Lock would fail. F_GETLK returned: \n");
			show_lock_info(&region_to_test);
		}
		else
			printf("F_WRLCK - Lock would succeed!! \n");

		// 再測試一個共享 (讀取)鎖，
		region_to_test.l_type = F_RDLCK;
		region_to_test.l_whence = SEEK_SET;
		region_to_test.l_start = start_byte;
		region_to_test.l_len = SIZE_TO_TRY;
		region_to_test.l_pid = -1;

		printf("Testing F_RDLCK on region from %d to %d. \n", start_byte, start_byte + SIZE_TO_TRY);

		// 再測試檔案
		res = fcntl(file_desc, F_GETLK, &region_to_test);
		if (res == -1) {
			fprintf(stderr, "F_GETLK failed!! \n");
			exit(EXIT_FAILURE);
		}
		if (region_to_test.l_pid != -1) {
			printf("Lock would fail. F_GETLK returned: \n");
			show_lock_info(&region_to_test);
		}
		else
			printf("F_RDLCK - Lock would succeed!! \n");
	}
	close(file_desc);

	return 0;
}

void 
show_lock_info(to_show)
struct flock *to_show;
{
	printf("\tl_type %d, ", to_show->l_type);
	printf("\tl_whence %d, ", to_show->l_whence);
	printf("\tl_start %d, ", to_show->l_start);
	printf("\tl_len %d, ", (int)to_show->l_len);
	printf("\tl_pid %d, ", to_show->l_pid);

	return;
}
