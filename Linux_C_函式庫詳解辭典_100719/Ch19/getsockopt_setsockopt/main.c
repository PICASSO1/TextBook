#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
int getsockopt(int s, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen);

1. int s: 用socket()函式所開啟的檔案描述子；
2. int level: 代表要設定的網路層；一般而言都是設定成"SOL_SOCKET"
3. int optname: 代表要被設定的選項；int level和int optname的定義在/ usr / include / asm-generic / socket.h
4. (const) void *optval: 要儲存回傳結果的記憶體位址；
5. socklen_t (*)optlen: (const) void *optval的記憶體位址空間大小

這兩個函式，可以針對用socket()函式所開啟的檔案描述子做設定；至於可以作哪些設定恐怕要有實務經驗。
*/

int main(void)
{
	int skfd = 0, optval = 0, optlen = sizeof(int);

	// 用socket()函式建立一個IPv4, UDP的檔案描述子
	skfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (skfd < 0) {
		perror("socket");
		close(skfd);
		return 1;
	}
	// 針對剛剛開啟的skfd檔案描述子，讀取socket層 (SOL_SOCKET)；且傳回socket的型態 (SO_TYPE)
	getsockopt(skfd, SOL_SOCKET, SO_TYPE, &optval, &optlen);
	printf("SOCK_DGRAM = %d (%d) \n", optval, optlen);
	// 定義在/ usr / include / bits / socket.h

	// 把這個skfd檔案描述子，取出"送出去的封包不要利用路由設備來傳輸"的值
	getsockopt(skfd, SOL_SOCKET, SO_DONTROUTE, &optval, &optlen);
	printf("Before setsockopt(): SO_DONTROUTE = %2d (%d) \n", optval, optlen);
	optval = -1;
	setsockopt(skfd, SOL_SOCKET, SO_DONTROUTE, &optval, optlen);
	getsockopt(skfd, SOL_SOCKET, SO_DONTROUTE, &optval, &optlen);
	printf("After  setsockopt(): SO_DONTROUTE = %d (%d) \n", optval, optlen);

	close(skfd);

	return 0;
}
