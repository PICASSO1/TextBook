#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define	IP_ADDR		"127.0.0.1"
#define	IP_PORT		9734

int main(void)
{
	int sockfd = 0, len = 0, result = 0;
	char ch = 'A';
	struct sockaddr_in address;

	// 產生一個客戶端的Socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// 命名Socket，讓它能夠符合Server端
	bzero((void *)&address, sizeof(struct sockaddr_in));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(IP_ADDR);
	address.sin_port = htons(IP_PORT);
	len = sizeof(struct sockaddr_in);
	// 連接到Server端的Socket
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1) {
		perror("oops: client1. ");
		exit(EXIT_FAILURE);
	}
	// 透過sockfd進行讀寫
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server = %c \n", ch);
	close(sockfd);
	exit(EXIT_SUCCESS);

	return 0;
}
