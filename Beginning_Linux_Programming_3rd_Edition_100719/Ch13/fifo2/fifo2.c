#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define	FIFO_NAME	"./my_fifo"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int res = 0;
	int open_mode = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <some combination of O_RDONLY | O_WRONLY | O_NONBLOCK>", *argv);
		exit(EXIT_FAILURE);
	}

	argv++;
	if (strncmp(*argv, "O_RDONLY", 8) == 0)
		open_mode |= O_RDONLY;
	else if (strncmp(*argv, "O_WRONLY", 8) == 0)
		open_mode |= O_WRONLY;
	else if (strncmp(*argv, "O_NONBLOCK", 10) == 0)
		open_mode |= O_NONBLOCK;
	else { }

	argv++;
	if (*argv) {
		if (strncmp(*argv, "O_RDONLY", 8) == 0)
			open_mode |= O_RDONLY;
		else if (strncmp(*argv, "O_WRONLY", 8) == 0)
			open_mode |= O_WRONLY;
		else if (strncmp(*argv, "O_NONBLOCK", 10) == 0)
			open_mode |= O_NONBLOCK;
		else { }
	}

	if (access(FIFO_NAME, F_OK) == -1) {
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0) {
			fprintf(stderr, "Could't create FIFO: %s \n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("Process %d opening FIFO. \n", (int)getpid());
	res = open(FIFO_NAME, open_mode);
	printf("Process %d result %d \n", (int)getpid(), res);
	sleep(5);
	if (res != -1)
		close(res);
	printf("Process %d finished!! \n", (int)getpid());

	return 0;
}
