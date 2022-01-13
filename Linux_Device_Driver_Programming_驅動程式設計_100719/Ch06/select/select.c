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
	fd_set rfds;
	struct timeval tv;
	ssize_t sz = 0;
	unsigned char buf[64];

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	bzero(&rfds, sizeof(fd_set));
	bzero(&tv, sizeof(struct timeval));
	do {
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		printf("select() .... \n");
		retval = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (retval == -1) {
			perror("select");
			break;
		}

		if (retval)
			break;
	} while (retval == 0);	// timeout elapsed

	if (FD_ISSET(fd, &rfds)) {
		printf("read() .... \n");
		memset(buf, '\0', sizeof(unsigned char) * 64);
		sz = read(fd, buf, sizeof(unsigned char) * 64);
		printf("read(): %d \n", sz);
		for (i = 0; i < sz; i++)
			printf("%02X ", buf[i]);
		printf("\n");
	}
	close(fd);

	return 0;
}
