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

int main(void)
{
	int res = 0;
	int open_mode = O_RDONLY;
	int pipe_fd = 0;
	int bytes_read = 0;
	char buffer[BUFFER_SIZE + 1];

	memset(&buffer, '\0', sizeof(char) * (BUFFER_SIZE + 1));
	printf("Process %d opening FIFO: O_RDONLY. \n", (int)getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result: %d. \n", (int)getpid(), pipe_fd);
	if (pipe_fd != -1) {
		do {
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			bytes_read += res;
		} while (res > 0);
		close(pipe_fd);
	}
	else
		exit(EXIT_FAILURE);

	printf("Process %d finished; %d bytes read.  \n", (int)getpid(), bytes_read);
	
	return 0;
}
