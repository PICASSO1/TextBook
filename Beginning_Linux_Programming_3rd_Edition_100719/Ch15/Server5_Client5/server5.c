#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <strings.h>

#define	IP_ADDR		"127.0.0.1"
#define	IP_PORT		9734

int main(void)
{
	int server_sockfd = 0, client_sockfd = 0;
	int server_len = 0, client_len = 0, result = -1;
	struct sockaddr_in server_address, client_address;
	fd_set readfds, testfds;

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
	// 初始化readfds結構
	bzero((void *)&readfds, sizeof(fd_set));
	FD_ZERO(&readfds);
	// 把Server Socket FD加入到readfds
	FD_SET(server_sockfd, &readfds);
	bzero((void *)&testfds, sizeof(fd_set));
	while (1) {
		char ch = 0x00;
		int fd = -1, nread = 0;

		testfds = readfds;
		printf("Server waiting .... \n");
		// 開使用select()函式偵測我們的readfds；看看是否有變化！
		result = select(FD_SETSIZE, &testfds, (fd_set *)NULL, (fd_set *)NULL, (struct timeval *)NULL);
		if (result < 1) {
			perror("select");
			exit(EXIT_FAILURE);
		}
		
		for (fd = 0; fd < FD_SETSIZE; fd++) {
			// 用FD_ISSET()巨集來檢查 FD檔案描述子
			if (FD_ISSET(fd, &testfds)) {
				// 如果這個檔案描述子，是剛剛建立的Server Socket FD
				if (fd == server_sockfd) {
					client_len = sizeof(struct sockaddr_in);
					// 接受Client連結 ....
					bzero((void *)&client_address, sizeof(struct sockaddr_in));
					client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
					// 再把Client Socket FD加入到readfds
					FD_SET(client_sockfd, &readfds);
					printf("adding client on fd: %d \n", client_sockfd);
				}
				// 假如這個檔案描述子，與Server Socket FD無關
				else {
					ioctl(fd, FIONREAD, &nread);
					if (nread == 0) {
						close(fd);
						// 就把這個FD從readfds中移除
						FD_CLR(fd, &readfds);
						printf("removing client on fd: %d \n", fd);
					}
					else {
						// 接收從Client傳來的資料！
						read(fd, (void *)&ch, sizeof(char));
						sleep(5);
						printf("serving client on fd: %d \n", fd);
						ch++;
						write(fd, (void *)&ch, sizeof(char));
					}
				}
			}
		}
	}

	return 0;
}
