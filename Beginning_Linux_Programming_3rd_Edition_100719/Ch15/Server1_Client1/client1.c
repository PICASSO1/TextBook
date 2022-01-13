#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define	SOCKET_PIPE	"server_socket"

int main(void)
{
	int sockfd = 0, len = 0, result = 0;
	char ch = 'A';
	struct sockaddr_un address;

	// 產生一個客戶端的Socket
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	// 命名Socket，讓它能夠符合Server端
	bzero((void *)&address, sizeof(struct sockaddr_un));
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, SOCKET_PIPE);
	len = sizeof(struct sockaddr_un);
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
