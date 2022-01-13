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
	unsigned char buf[64];
	ssize_t sz = 0;

	fd = open(DEVFILE, O_RDWR);	// different from non-block.c
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("read() .... \n");

	memset(buf, '\0', sizeof(unsigned char) * 64);
	sz = read(fd, buf, sizeof(unsigned char) * 64);
	printf("read(): %d \n", sz);
	if (sz > 0) {
		for (i = 0; i < sz; i++)
			printf("%02X ", buf[i]);
		printf("\n");
	}
	else {
		printf("error %d \n", errno);
		perror("read");
	}
	close(fd);

	return 0;
}
