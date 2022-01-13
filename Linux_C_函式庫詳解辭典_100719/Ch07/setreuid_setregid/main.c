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
*	1. "re" is to mean "Real and Effective", ....
*/

int 
main()
{
	gid_t regid = 500U;
	uid_t reuid = 500U;

	if (setregid(-1, regid) == -1) {
		perror("setregid");
		exit(EXIT_FAILURE);
	}
	regid = getegid();
	fprintf(stdout, "This process NEW Real and Effective Group ID is: %u \n", regid);

	if (setreuid(-1, reuid) == -1) {
		perror("setreuid");
		exit(EXIT_FAILURE);
	}
	reuid = geteuid();
	fprintf(stdout, "This process NEW Real and Effective User ID is: %u \n", reuid);

	return 0;
}
