#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void 
handler()
{
	printf("Hello!! World!! \n");
	return;
}

int 
main()
{
	int i = 0;

	signal(SIGALRM, handler);
	alarm(5);
	for (i = 1; i < 7; i++) {
		printf("Sleep %d.... \n", i);
		sleep(1);
	}

	return 0;
}
