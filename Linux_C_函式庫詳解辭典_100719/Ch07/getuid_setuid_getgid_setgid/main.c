#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
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
*	1. 這裡的UID (User ID), GID (Group ID)就是指"/etc/passwd"檔案中的第3, 第4欄位!!
*/

int 
main()
{
	gid_t gid = 0U;
	uid_t uid = 0U;

	gid = getgid();
	fprintf(stdout, "This process Group ID is: %u \n", gid);
	
	uid = getuid();
	fprintf(stdout, "This process User ID is: %u \n", uid);

	gid = (unsigned int)500;
	if (setgid(gid) == -1) {
		perror("setgid");
		exit(EXIT_FAILURE);
	}
	gid = getgid();
	fprintf(stdout, "This process NEW Group ID is: %u \n", gid);

	uid = (unsigned int)500;
	if (setuid(uid) == -1) {
		perror("setuid");
		exit(EXIT_FAILURE);
	}
	uid = getuid();
	fprintf(stdout, "This process NEW User ID is: %u \n", uid);

	return 0;
}
