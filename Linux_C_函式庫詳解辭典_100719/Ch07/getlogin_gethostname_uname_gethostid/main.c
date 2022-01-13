#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <string.h>

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
*	1. 
*/

int 
main()
{
	char *ptr = (char *)NULL;
	char szTemp[64];
	struct utsname stUname;
	long lnHostId = 0L;
	
	// Get the login name;
	ptr = getlogin();
	if (ptr == NULL) {
		perror("getlogin");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "The login name: %s \n\n", ptr);

	// Get the Host Name;
	memset(szTemp, '\0', sizeof(char) * 64);
	if (gethostname(szTemp, sizeof(char) * 64) == -1) {
		perror("gethostname");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "The Host Name is: %s \n\n", szTemp);

	// Get the "uname" information....
	bzero((void *)&stUname, sizeof(struct utsname));
	if (uname(&stUname) == -1) {
		perror("uname");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "The uname() System Name: %s \n", stUname.sysname);	// Name of the implementation of the operating system.
	fprintf(stdout, "The uname() Node Name: %s \n", stUname.nodename);	// Name of this node on the network.
	fprintf(stdout, "The uname() Release: %s \n", stUname.release);			// Current release level of this implementation.
	fprintf(stdout, "The uname() Version: %s \n", stUname.version);			// Current version level of this release.
	fprintf(stdout, "The uname() Machine: %s \n\n", stUname.machine);			// Name of the hardware type the system is running on.

	//Get the Host ID.
	lnHostId = gethostid();
	fprintf(stdout, "The Host ID is: %ld \n\n", lnHostId);
	
	return 0;
}
