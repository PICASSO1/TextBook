#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = (pid_t)0, child_pid = (pid_t)5;
	char *message = NULL;
	int n = -9, exit_code = 8, stat_val = -1;

	printf("fork() program starting.... \n");
	pid = fork();
	switch (pid) {
		case -1:
			perror("fork failed!! ");
			exit(1);
		case 0:
			message = "This is the CHILD!! \n";
			n = 5;
			exit_code = 37;
			break;
		default:
			message = "This is the PARENT. \n";
			n = 3;
			exit_code = 66;
			break;			
	}

	for (; n > 0; n--) {
		puts(message);
		sleep(1);
	}

	if (pid != 0) {
		child_pid = wait(&stat_val);
		printf("Child has finished: PID = %d \n", (int)child_pid);
		if (WIFEXITED(stat_val) != 0)
			printf("Child exited with code %d \n", WEXITSTATUS(stat_val));
		else
			printf("Child terminated abnormally. \n");
	}

	return exit_code;
}
