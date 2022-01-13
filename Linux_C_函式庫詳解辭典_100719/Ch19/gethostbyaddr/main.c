#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

/*
struct hostent *gethostbyaddr(const void *addr, int len, int type);

// / usr / include / netdb.h
struct hostent {
	char *h_name;		// 正式的主機名稱
	char **h_aliases;		// 指向主機名稱的其他別名
	int h_addrtype;		// 位址的型態，通常是AF_INET；定義在/ user / include / bits / socket.h
	int h_length;			// 位址的長度
	char **h_addr_list;	// 從名稱伺服器取得該主機的所有位址
};

簡言之，是藉由IP Address來查詢Host的資訊！

// / usr / include / netinet / in.h
typedef uint32_t in_addr_t;
struct in_addr {
	in_addr_t s_addr;
};

struct sockaddr_in {
	__SOCKADDR_COMMON(sin_);
	in_port_t sin_port;			// Port number. 
	struct in_addr sin_addr;	// Internet address. 
	// Pad to size of `struct sockaddr'.
	unsigned char sin_zero[ \
		sizeof(struct sockaddr) - __SOCKADDR_COMMON_SIZE - sizeof(in_port_t) - sizeof(struct in_addr) \
	];
};
*/

int main(void)
{
	struct hostent *stHost = (struct hostent *)NULL;
	struct in_addr stInAddr, stTempInAddr;
	int nRet = 0, idx = -1;
	struct sockaddr_in stSkAddr;

	bzero((void *)&stInAddr, sizeof(struct in_addr));
	nRet = inet_aton("127.0.0.1", &stInAddr);

	stHost = gethostbyaddr(&stInAddr, sizeof(struct in_addr), AF_INET);
	if (stHost == (struct hostent *)NULL) {
		herror("gethostbyaddr");
		return 1;
	}

	printf("gethostbyaddr(): \n");
	printf("stHost->h_name: %s \n", stHost->h_name);
	printf("\n");

	idx = 0;
	do {
		printf("stHost->h_aliases: %s \n", stHost->h_aliases[idx]);
		idx++;
	} while (stHost->h_aliases[idx] != (char *)NULL);
	printf("\n");

	printf("stHost->h_addrtype = %d \n", stHost->h_addrtype);
	// Address Type定義在 / usr / include / bits / socket.h; 例如2 == PF_INET == AF_INET
	printf("stHost->h_length = %d \n", stHost->h_length);
	printf("\n");

	idx = 0;
	do {
		printf("stHost->h_addr_list: %s \n", stHost->h_addr_list[idx]);
		idx++;
	} while (stHost->h_addr_list[idx] != (char *)NULL);
	// 在/ usr / include / netdb.h中有定義h_addr就是h_addr_list[0]!! 
	bzero((void *)&stTempInAddr, sizeof(struct in_addr));
	bzero((void *)&stSkAddr, sizeof(struct sockaddr_in));
	memcpy(&stSkAddr.sin_addr.s_addr, stHost->h_addr, 4);
	stTempInAddr.s_addr = stSkAddr.sin_addr.s_addr;
	printf("IP Address: %s \n", inet_ntoa(stTempInAddr));

	return 0;
}
