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
	int server_sockfd = 0, client_sockfd = 0;
	int server_len = 0, client_len = 0;
	struct sockaddr_in server_address, client_address;

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// 命名Socket ....
	bzero((void *)&server_address, sizeof(struct sockaddr_in));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(IP_PORT);
	server_len = sizeof(struct sockaddr_in);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	// 產生一個listen佇列 (queue)，等待客戶端
	listen(server_sockfd, 5);
	while (1) {
		char ch = 0x00;

		printf("Server waiting .... \n");
		client_len = sizeof(struct sockaddr_in);
		// 接受連結 ....
		bzero((void *)&client_address, sizeof(struct sockaddr_in));
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		// 透過client_sockfd進行讀寫
		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		
		close(client_sockfd);
	}

	return 0;
}
