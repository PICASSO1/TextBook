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
	const char some_data[] = "123";
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
		
		if (fork_result == 0) {	/* Child process */
			data_processed = read(file_pipes[0], (void *)buffer, BUFSIZ);
			printf("Read %d bytes: %s \n", data_processed, buffer);
			exit(EXIT_SUCCESS);
		}
		else {	/* Parent process */
			data_processed = write(file_pipes[1], (void *)some_data, strlen(some_data));
			printf("Wrote %d bytes!! \n", data_processed);
		}
	}
	exit(EXIT_FAILURE);
/*	return 0;	*/
}
/*
1. The popen() / pclose() were the high level I/O, you must use fread() / fwrite();
2. But pipe() is the law level I/O, you must use read() / write() function.

#include <unistd.h>
1. ssize_t read(int fd, void *buf, size_t count);
2. ssize_t write(int fd, const void *buf, size_t count);
*/