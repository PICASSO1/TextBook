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
// Presentation to Network
int inet_pton(int af, const char *src, void *dst);

// Network to Presentation
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
*/

int main(void)
{
	int nRet = -1;
	struct in_addr stInAddr;
	char *ptr = (char *)NULL;
	char strIPv4Address[INET_ADDRSTRLEN];

	bzero((void *)&stInAddr, sizeof(struct in_addr));
	nRet = inet_pton(AF_INET, "127.0.0.1", &stInAddr);
	if (nRet == -1) {
		herror("inet_pton");
		exit(EXIT_FAILURE);
	}
	printf("IPv4 inet_pton(): 0x%08X (%d) \n\n", stInAddr.s_addr, stInAddr.s_addr);

	memset(strIPv4Address, '\0', sizeof(char) * INET_ADDRSTRLEN);
	ptr = inet_ntop(AF_INET, (void *)&stInAddr, strIPv4Address, sizeof(char) * INET_ADDRSTRLEN);
	if (ptr == (char *)NULL){
		herror("inet_ntop");
		exit(EXIT_FAILURE);
	}
	printf("IPv4 inet_ntop(): ptr = %s (%d); strIPv4Address: %s (%d) \n\n", \
		ptr, strlen(ptr), strIPv4Address, strlen(strIPv4Address));

	return 0;
}
