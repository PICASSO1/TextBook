#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

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
*	1. int mkdir(const char *path, mode_t mode);
*	2. The second argument -- "mode_t mode" could be:
*		S_IRUSR		// Is Read User
*		S_IWUSR		// Is Write User
*		S_IXUSR		// Is Executable User
*		S_IRWXU ( == S_IRUSR | S_IWUSR | S_IXUSR )
*		S_IRGRP		// Is Read Group
*		S_IWGRP		// Is Write Group
*		S_IXGRP		// Is Executable Group
*		S_IRWXG  (== S_IRGRP | S_IWGRP | S_IXGRP )
*		S_IROTH		// Is Read Others
*		S_IWOTH		// Is Write Others
*		S_IXOTH		// Is Executable Others
*		S_IRWXO ( == S_IROTH | S_IWOTH | S_IXOTH )
*		S_ISUID		// Is Set User ID (SUID); Binary File only, not Directory
*		S_ISGID 		// Is Set Group ID (SGID); Both of the Binary File and the Directory
*		S_ISVTX		// Is Sticky Bit (SBIT); Directory ony, not the Binary File
*/

#define	DIRECTORY_NAME	"./TEST"

int 
main()
{
	int nRet = -1;
	
	nRet = mkdir(DIRECTORY_NAME, S_IRWXU | S_IRWXG | S_IRWXO);
	if (nRet == -1) {
		perror("mkdir");
		exit(EXIT_FAILURE);
	}
	printf("Create a new directory: %s \n", DIRECTORY_NAME);

	nRet = rmdir(DIRECTORY_NAME);
	if (nRet == -1) {
		perror("rmdir");
		exit(EXIT_FAILURE);
	}
	printf("Remove a just directory: %s \n", DIRECTORY_NAME);

	return 0;
}
