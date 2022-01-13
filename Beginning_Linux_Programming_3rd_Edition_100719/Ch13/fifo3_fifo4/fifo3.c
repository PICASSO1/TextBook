#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#define	_POSIX_PIPE_BUF	512
#define	_POSIX_HIWAT	_POSIX_PIPE_BUF
/* Define in: bits / posix1_lim.h */
#define	PIPE_BUF		_POSIX_HIWAT

#define	FIFO_NAME	"./my_fifo"
#define	BUFFER_SIZE	PIPE_BUF
#define	TEN_MEG	(1024 * 1024 * 10)

int main(void)
{
	int res = 0;
	int open_mode = O_WRONLY;
	int pipe_fd = 0;
	int bytes_sent = 0;
	char buffer[BUFFER_SIZE + 1];

	if (access(FIFO_NAME, F_OK) == -1) {
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0) {
			fprintf(stderr, "Could't create FIFO: %s \n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("Process %d opening FIFO: O_WRONLY. \n", (int)getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result: %d. \n", (int)getpid(), pipe_fd);
	if (pipe_fd != -1) {
		while (bytes_sent < TEN_MEG) {
			res = write(pipe_fd, buffer, BUFFER_SIZE);
			if (res == -1) {
				fprintf(stderr, "Write error on pipe. \n");
				exit(EXIT_FAILURE);
			}
			bytes_sent += res;
		}
		close(pipe_fd);
	}
	else
		exit(EXIT_FAILURE);
	
	printf("Process %d finished!! \n", (int)getpid());

	return 0;
}
