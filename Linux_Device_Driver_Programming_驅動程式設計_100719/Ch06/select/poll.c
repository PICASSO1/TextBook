#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd = -1, i = -1, retval = -1;
	struct pollfd fds;
	unsigned char buf[64];
	ssize_t sz = 0;

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	do {
		fds.fd = fd;
		fds.events = POLLIN;
		printf("poll() .... \n");
		retval = poll(&fds, 1, 5 * 1000);
		if (retval == -1) {
			perror("poll");
			break;
		}

		if (retval)
			break;
	} while (retval == 0);	// timeout elapsed 

	memset(buf, '\0', sizeof(unsigned char) * 64);
	if (fds.revents & POLLIN) {
		printf("read() .... \n");
		sz = read(fd, buf, sizeof(unsigned char) * 64);
		printf("read(): %d \n", sz);
		for (i = 0; i < sz; i++)
			printf("%02X ", buf[i]);
		printf("\n");
	}
	close(fd);

	return 0;
}
