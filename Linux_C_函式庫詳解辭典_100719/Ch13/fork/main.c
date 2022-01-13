#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid_tRet = fork();

	if (pid_tRet == (pid_t)0) {
		printf("This is the child process!! \n");
		printf("1. fork() = %d \n", (int)pid_tRet);
	}
	else	{
		printf("This is the parent process!! \n");
		printf("2. fork() = %d \n", (int)pid_tRet);
	}
	sleep(60);

	return 0;
}
