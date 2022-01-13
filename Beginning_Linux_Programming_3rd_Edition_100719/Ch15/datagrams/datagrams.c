#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	char *host = (char *)NULL;
	int sockfd = 0, result = -1;
	struct sockaddr_in address;
	struct hostent *hostinfo = (struct hostent *)NULL;
	struct servent *servinfo = (struct servent *)NULL;
	char buffer[128];
	socklen_t skLen = -1;

	host = (argc == 1)? "localhost": argv[1];
	/* 找出主機位址；如果沒有發現就回報錯誤 */
	hostinfo = gethostbyname(host);
	if (hostinfo == (struct hostent *)NULL) {
		fprintf(stderr, "No Host: %s \n", host);
		return 1;
	}
	/* 檢查主機是否有DayTime服務 */
	servinfo = getservbyname("daytime", "ucp");
	if (servinfo == (struct servent *)NULL) {
		fprintf(stderr, "No DayTime service!! \n");
		return 1;
	}
	printf("DayTime Port is: %d \n", ntohs(servinfo->s_port));
	/* 建立一個Socket */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	/* 建立connect需要的位址部份 */
	bzero((void *)&address, sizeof(struct sockaddr_in));
	address.sin_family = AF_INET;
	address.sin_port = servinfo->s_port;
	address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;
	/* 隨後連結，再取得資訊 */
	memset(buffer, '\0', sizeof(char) * 128);
	result = sendto(sockfd, (void *)buffer, 1, 0, (struct sockaddr *)&address, sizeof(struct sockaddr));
/*	result = connect(sockfd, (struct sockaddr *)&address, sizeof(struct sockaddr));
	if (result == -1) {
		perror("connect");
		return 1;
	}

	memset(buffer, '\0', sizeof(char) * 128);
	result = read(sockfd, buffer, sizeof(char) * 128);
*/	skLen = sizeof(struct sockaddr);
	result = recvfrom(sockfd, buffer, sizeof(char) * 128, 0, (struct sockaddr *)&address, &skLen);
	buffer[result] = '\0';
	printf("Read %d bytes: %s \n", result, buffer);
	close(sockfd);

	return 0;
}
