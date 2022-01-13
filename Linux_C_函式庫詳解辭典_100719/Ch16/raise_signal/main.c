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
	signal(SIGUSR1, handler);
	(int)raise(SIGUSR1);

	return 0;
}
