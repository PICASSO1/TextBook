#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd = -1, status = 0;

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	if (fork() == 0) {
		sleep(3);
		close(fd);
		return 1;
	}
	wait(&status);
	sleep(3);
	close(fd);
	showDmesg();

	return 0;
}
