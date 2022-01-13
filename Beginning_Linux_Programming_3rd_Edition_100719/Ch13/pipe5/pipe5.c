#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>

int 
main(void)
{
	int data_processed = 0;
	int file_pipes[2];
	const char some_data[] = "Hello!! World!! ";
	char buffer[BUFSIZ + 1];
	pid_t fork_result = (pid_t)0;

	memset(&buffer, '\0', sizeof(char) * (BUFSIZ + 1));
	bzero((void *)&file_pipes, sizeof(int) * 2);
	if (pipe(file_pipes) == 0) {
		fork_result = fork();
		if (fork_result == -1) {
			fprintf(stderr, "Fork failure!! \n");
			exit(EXIT_FAILURE);
		}
		
		if (fork_result == (pid_t)0) {	/* Child process */
			close(0);	/* 0: stdin */
			dup(file_pipes[0]);
			close(file_pipes[0]);
			close(file_pipes[1]);
			execl("/usr/bin/od", "od", "-c", (char *)NULL);
			exit(EXIT_FAILURE);
		}
		else {	/* Parent process */
			close(file_pipes[0]);
			data_processed = write(file_pipes[1], (void *)some_data, strlen(some_data));
			close(file_pipes[1]);
			printf("%d - wrote %d bytes. \n", (int)getpid(), data_processed);
		}
	}
	exit(EXIT_SUCCESS);
/*	return 0;	*/
}
