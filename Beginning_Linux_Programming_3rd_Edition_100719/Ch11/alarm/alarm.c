#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

static int 
alarm_fired = 0;

void 
ding(sig)
int sig;
{
	alarm_fired = 1;
	return;
}

int 
main()
{
	pid_t pid = (pid_t)0;

	printf("Alarm Application starting!! \n");
	pid = fork();
	switch (pid) {
		case -1:
			perror("fork() failed!! \n");
			exit(1);
		case 0:
			sleep(5);
			kill(getppid(), SIGALRM);
			exit(0);
		default:
			break;
	}

	printf("Waiting for ALaRM to go off!! \n");
	signal(SIGALRM, ding);
	pause();
	if (alarm_fired != 0)
		printf("Ding!! \n");

	printf("Done!! \n");

	return 0;
}
