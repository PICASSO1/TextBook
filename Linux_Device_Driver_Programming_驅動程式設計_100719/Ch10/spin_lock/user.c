#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd = -1, i = -1;
	ssize_t size = 0;
	char buf[32];

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	for (;;) {
		size = read(fd, buf, sizeof(char) * 32);
		for (i = 0; i < size; i++)
			printf("0x%02X ", buf[i] & 0xFF);
		printf("\n");
		sleep(3);
	}
	close(fd);

	return 0;
}
