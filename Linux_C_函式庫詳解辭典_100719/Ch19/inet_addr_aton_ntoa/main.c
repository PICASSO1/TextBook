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
unsigned long int inet_addr(const char *cp);

// ASCII to Network
int inet_aton(const char *cp, struct in_addr *inp);
struct in_addr {
	unsigned long int s_addr;
};

// Network to ASCII
char *inet_ntoa(struct in_addr in);
*/

int main(void)
{
	unsigned long int ulnRet = 0UL;
	int nRet = 0;
	struct in_addr stInAddr;
	char *ptr = (char *)NULL;

	ulnRet = inet_addr("192.168.1.1");
	if (ulnRet == -1) {
		herror("inet_addr");
		exit(EXIT_FAILURE);
	}
	printf("IPv4 inet_addr(\"192.168.1.1\") = 0x%08X (%d) \n\n", ulnRet, ulnRet);

	bzero((void *)&stInAddr, sizeof(struct in_addr));
	nRet = inet_aton("192.168.1.1", &stInAddr);
	if (nRet == -1) {
		herror("inet_aton");
		exit(EXIT_FAILURE);
	}
	printf("IPv4 inet_aton(): nRet = %d; stInAddr.s_addr = 0x%08X (%d) \n\n", \
		nRet, stInAddr.s_addr, stInAddr.s_addr);

	ptr = inet_ntoa(stInAddr);
	if (ptr == (char *)NULL) {
		herror("inet_ntoa");
		exit(EXIT_FAILURE);
	}
	printf("IPv4 inet_ntoa(): %s (%d);  \n\n", ptr, strlen(ptr));

	return 0;
}
