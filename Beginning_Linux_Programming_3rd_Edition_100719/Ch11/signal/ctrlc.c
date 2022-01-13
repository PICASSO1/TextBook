#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void 
ouch(sig)
int sig;
{
	printf("OUCH!! -I got signal %d \n", sig);
	signal(SIGINT, SIG_DFL);
	return;
}

int 
main()
{
	signal(SIGINT, ouch);
	while (1) {
		printf("Hello!! World!! \n");
		sleep(1);
	}
	return 0;
}
