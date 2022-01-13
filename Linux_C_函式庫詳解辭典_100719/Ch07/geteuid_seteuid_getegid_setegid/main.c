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
*	1. Effective, ....
*/

int 
main()
{
	gid_t egid = 0U;
	uid_t euid = 0U;

	egid = getegid();
	fprintf(stdout, "This process Effective Group ID is: %u \n", egid);
	
	euid = geteuid();
	fprintf(stdout, "This process Effective User ID is: %u \n", euid);

	egid = (unsigned int)500;
	if (setegid(egid) == -1) {
		perror("setegid");
		exit(EXIT_FAILURE);
	}
	egid = getegid();
	fprintf(stdout, "This process NEW Effective Group ID is: %u \n", egid);

	euid = (unsigned int)500;
	if (seteuid(euid) == -1) {
		perror("seteuid");
		exit(EXIT_FAILURE);
	}
	euid = geteuid();
	fprintf(stdout, "This process NEW User ID is: %u \n", euid);

	return 0;
}
