#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void 
ouch(sig)
int sig;
{
	printf("OUCH!! -I got signal %d \n", sig);
	return;
}

int 
main()
{
	struct sigaction act;

/*	bzero(&act, sizeof(struct sigaction));	*/
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);
	while (1) {
		printf("Hello!! World!! \n");
		sleep(1);
	}
	return 0;
}
