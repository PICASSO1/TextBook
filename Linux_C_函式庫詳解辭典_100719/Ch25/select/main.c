#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval = -2;
	char buf[100];
	char *p = NULL;

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec = 5;
	tv.tv_usec = 0;
	retval = select(1, &rfds, NULL, NULL, &tv);
	if (retval == -1)
		perror("select()");
	else if (retval != 0) {
		printf("Data is available now. \n");
		if (FD_ISSET(0, &rfds)) {
			read(0, buf, sizeof(buf));
			p = strchr(buf, '\n');
			if (p != NULL)
				*p = '\0';
			printf("You type: %s \n", buf);
		}
	}
	else	// if (retval == 0)
		printf("No data within five seconds. \n");

	return 0;
}
