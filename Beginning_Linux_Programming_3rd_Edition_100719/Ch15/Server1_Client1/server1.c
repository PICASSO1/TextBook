#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>

#define	SOCKET_PIPE	"server_socket"

int main(void)
{
	int server_sockfd = 0, client_sockfd = 0;
	int server_len = 0, client_len = 0;
	struct sockaddr_un server_address, client_address;

	// 移除一個舊的Socket，產生一個新的Socket
	unlink(SOCKET_PIPE);
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	// 命名Socket ....
	bzero((void *)&server_address, sizeof(struct sockaddr_un));
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, SOCKET_PIPE);
	server_len = sizeof(struct sockaddr_un);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	// 產生一個listen佇列 (queue)，等待客戶端
	listen(server_sockfd, 5);
	while (1) {
		char ch = 0x00;

		printf("Server waiting .... \n");
		client_len = sizeof(struct sockaddr_un);
		// 接受連結 ....
		bzero((void *)&client_address, sizeof(struct sockaddr_un));
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
		// 透過client_sockfd進行讀寫
		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		
		close(client_sockfd);
	}

	return 0;
}
