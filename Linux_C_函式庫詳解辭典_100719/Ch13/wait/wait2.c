#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define	SLEEP_SECONDS	5

int main(void)
{
	pid_t pid = (pid_t)0;
	int status = 0, i = 0;

	if (fork() == (pid_t)0) {
		printf("The child process PID was: %d \n", getpid());
		system("./Hello");
		exit(status);
	}
	else	{
		printf("The parent process PID was: %d \n", getpid());
		printf("Wait %d seconds....\n", SLEEP_SECONDS);
		sleep(SLEEP_SECONDS);
		system("./World");
		pid = wait(&status);
		i = WEXITSTATUS(status);
		printf("Child's pid = %d, exit status = %d \n", pid, i);
	}

	return 0;
}
