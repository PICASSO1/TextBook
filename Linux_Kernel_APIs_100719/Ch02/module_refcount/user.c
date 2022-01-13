#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd0 = -1, fd1 = -1;

	fd0 = open("/dev/example0", O_RDWR);
	fd1 = open("/dev/example1", O_RDWR);

	close(fd1);
	close(fd0);

	return 0;
}
