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
int 
getnameinfo(sa, salen, host, hostlen, serv, servlen, flags);
const struct sockaddr *sa;
socklen_t salen;
char *host;
size_t hostlen;
char *serv;
size_t servlen;
int flags;
*/
int main(void)
{
	struct sockaddr_in stSockAddrIn;
	char strHostName[32], strServName[32];
	int nRet = -1;

	bzero((void *)&stSockAddrIn, sizeof(struct sockaddr_in));
	inet_pton(AF_INET, "127.0.0.1", &stSockAddrIn.sin_addr);
	stSockAddrIn.sin_family = AF_INET;
	stSockAddrIn.sin_port = htons(4096);

	memset(strHostName, '\0', sizeof(char) * 32);
	memset(strServName, '\0', sizeof(char) * 32);
	nRet = getnameinfo((struct sockaddr *)&stSockAddrIn, sizeof(struct sockaddr), 
		strHostName, sizeof(char) * 32, strServName, sizeof(char) * 32, NI_NOFQDN);
	if (nRet != 0) {
		fprintf(stderr, "getaddrinfo() error: %s \n", gai_strerror(nRet));
		exit(EXIT_FAILURE);
	}

	printf("strHostName: %s (%d) \n", strHostName, strlen(strHostName));
	printf("strServName: %s (%d) \n", strServName, strlen(strServName));

	return 0;
}
