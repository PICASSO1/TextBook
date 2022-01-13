#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030316
*
*	Date: 2016 / 03 / 03
*
*	Description: 
*	1. The struct dirent was defined at: /usr/include/bits/dirent.h
*		struct dirent {
*			__ino_t d_ino;	// __ino_t == unsigned long int;
*			__off_t d_off;	// __off_t == long int
*			unsigned short int d_reclen;
*			unsigned char d_type;
*			char d_name[256];
*		};
*/

#define	DIRECTORY_NAME	"./TEST"

int 
main()
{
	DIR *dp = (DIR *)NULL;
	struct dirent *p_stDir = (struct dirent *)NULL;
	int nRet = -1;
	long int lnOffset = 0L, lnOffsetIdx = 3L;

	dp = opendir(DIRECTORY_NAME);
	if (dp == (DIR *)NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	printf("Open the directory: %s \n", DIRECTORY_NAME);

	while ((p_stDir = readdir(dp)) != (struct dirent *)NULL) {
		if ((strcmp(p_stDir->d_name, ".", 1) == 0) || (strcmp(p_stDir->d_name, "..", 2) == 0))
			continue;
		lnOffset = telldir(dp);
		printf("0. p_stDir->d_ino: %u \n", p_stDir->d_ino);
		printf("0. p_stDir->d_off: %ld \n", p_stDir->d_off);
		printf("0. p_stDir->d_reclen: %u \n", p_stDir->d_reclen);
		printf("0. p_stDir->d_type: 0x%02X \n", p_stDir->d_type);
		printf("0. p_stDir->d_name: %s \n", p_stDir->d_name);
		printf("0. telldir() offset: %ld \n", lnOffset);
		puts("");
		if (strncmp(p_stDir->d_name, "5.TXT", 5) == 0)
			lnOffsetIdx = lnOffset;	// Record the offset value of "5.TXT" ....
	}

	printf("Read again, but from \"5.TXT\" .... \n");
	seekdir(dp, lnOffsetIdx);
	while ((p_stDir = readdir(dp)) != (struct dirent *)NULL) {
		if ((strcmp(p_stDir->d_name, ".", 1) == 0) || (strcmp(p_stDir->d_name, "..", 2) == 0))
			continue;
		lnOffset = telldir(dp);
		printf("1. p_stDir->d_ino: %u \n", p_stDir->d_ino);
		printf("1. p_stDir->d_off: %ld \n", p_stDir->d_off);
		printf("1. p_stDir->d_reclen: %u \n", p_stDir->d_reclen);
		printf("1. p_stDir->d_type: 0x%02X \n", p_stDir->d_type);
		printf("1. p_stDir->d_name: %s \n", p_stDir->d_name);
		printf("1. telldir() offset: %ld \n", lnOffset);
		puts("");
	}

	printf("Read again from head .... \n");
	rewinddir(dp);
	while ((p_stDir = readdir(dp)) != (struct dirent *)NULL) {
		if ((strcmp(p_stDir->d_name, ".", 1) == 0) || (strcmp(p_stDir->d_name, "..", 2) == 0))
			continue;
		lnOffset = telldir(dp);
		printf("2. p_stDir->d_ino: %u \n", p_stDir->d_ino);
		printf("2. p_stDir->d_off: %ld \n", p_stDir->d_off);
		printf("2. p_stDir->d_reclen: %u \n", p_stDir->d_reclen);
		printf("2. p_stDir->d_type: 0x%02X \n", p_stDir->d_type);
		printf("2. p_stDir->d_name: %s \n", p_stDir->d_name);
		printf("2. telldir() offset: %ld \n", lnOffset);
		puts("");
	}
	
	nRet = closedir(dp);
	if (nRet == -1) {
		perror("closedir");
		exit(EXIT_FAILURE);
	}
	printf("Close the directory: %s \n", DIRECTORY_NAME);

	return 0;
}
