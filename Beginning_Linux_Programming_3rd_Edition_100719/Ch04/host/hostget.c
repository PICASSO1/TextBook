#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <string.h>

int 
main()
{
	char computer[256];
	struct utsname uts;

	memset(computer, '\0', sizeof(char) * 256);
	bzero((void *)&uts, sizeof(struct utsname));
	if (gethostname(computer, (sizeof(char) * 256) - 1) || uname(&uts) < 0) {
		fprintf(stderr, "Could not get host information!! \n");
		exit(EXIT_FAILURE);
	}

	printf("Computer Host name is %s \n", computer);
	printf("uts.sysname: %s \n", uts.sysname);
	printf("uts.nodename: %s \n", uts.nodename);
	printf("uts.release: %s \n", uts.release);
	printf("uts.version: %s \n", uts.version);
	printf("uts.machine: %s \n", uts.machine);

	printf("Host ID: %ld \n", gethostid());
	
	return 0;
}

/*
Note: The struct utsname defined in: / usr / include / sys / utsname.h

struct utsname {
	char sysname[];
	char nodename[];
	char release[];
	char version[];
	char machine[];
};
*/
