#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main()
{
	pid_t pid = (pid_t)0;
	char *message = NULL;
	int n = -9;

	printf("fork() program starting.... \n");
	pid = fork();
	switch (pid) {
		case -1:
			perror("fork failed!! ");
			exit(1);
		case 0:
			message = "This is the CHILD!! \n";
			n = 3;
			break;
		default:
			message = "This is the PARENT. \n";
			n = 5;
			break;			
	}

	for (; n > 0; n--) {
		puts(message);
		sleep(1);
	}

	return 0;
}
