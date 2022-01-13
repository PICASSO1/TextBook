#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = (pid_t)0;
	int status = 0, i = 0;
	
	if (fork() == 0) {
		printf("This is the child process, pid_t = %d. \n", getpid());
		exit(1);
	}
	else {
		sleep(1);
		printf("This is the parent process, wait for child....\n");
		pid = wait(&status);
		i = WEXITSTATUS(status);
		printf("Child's pid = %d, exit status = %d \n", pid, i);
	}

	return 0;
}
