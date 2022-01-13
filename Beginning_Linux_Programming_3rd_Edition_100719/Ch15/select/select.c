#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char buffer[128];
	int result = -1, nread = -1;

	fd_set inputs, testfds;
	struct timeval timeout;

	bzero(&inputs, sizeof(fd_set));
	FD_ZERO(&inputs);
	FD_SET(0, &inputs);

	bzero(&testfds, sizeof(fd_set));
	while (1) {
		testfds = inputs;
		timeout.tv_sec = 2;
		timeout.tv_usec = 500000;

		result = select(FD_SETSIZE, &testfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
		switch (result) {
			case 0:
				printf("TimeOut!! \n");
				break;
			case -1:
				perror("select");
				exit(EXIT_FAILURE);
			/*	break; */
			default:
				if (FD_ISSET(0, &testfds)) {
					ioctl(STDIN_FILENO, FIONREAD, &nread);
					if (nread == 0) {
						printf("KeyBoard DONE!! \n");
						exit(EXIT_SUCCESS);
					}
					nread = read(0, buffer, nread);
					buffer[nread] = '\0';
					printf("read %d from keyboard: %s \n", nread, buffer);
				}
				break;
		}
	}

	return 0;
}
