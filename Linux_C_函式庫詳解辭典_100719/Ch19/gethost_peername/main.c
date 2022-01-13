#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

/*
// define in: /usr/include/sys/unistd.h
int gethostname(char *name, size_t len);

// define in: /usr/include/sys/socket.h
int getpeername(int s, struct sockaddr *addr, socklen_t len);
*/

int main(void)
{
	int nRet = -1;
	char strHostName[32];

	memset(strHostName, '\0', sizeof(char) * 32);
	nRet = gethostname(strHostName, sizeof(char) * 32);
	if (nRet == -1) {
		herror("gethostname");
		exit(EXIT_FAILURE);
	}
	printf("gethostname(): strHostName: %s (%d) \n", strHostName, strlen(strHostName));

	return 0;
}
