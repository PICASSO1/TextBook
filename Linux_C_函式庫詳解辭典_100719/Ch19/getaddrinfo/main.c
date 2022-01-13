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
struct addrinfo {
	int ai_flags;				
	// AI_PASSIVE, AI_CANONNAME, etc.. `/usr/include/netdb.h`
	int ai_family;				
	// AF_UNSPEC, AF_INET, AF_INET6, etc.. `/usr/include/bits/socket.h`
	int ai_socktype;			
	// SOCK_STREAM, SOCK_DGRAM, SOCK_RAW, etc.. `/usr/include/bits/socket.h`
	int ai_protocol;			// Protocol for socket??
	socklen_t ai_addrlen;		// Length of socket address??
	struct sockaddr *ai_addr;	// Socket address for socket. 
	char *ai_canonname;		// Canonical name for service location. 
	struct addrinfo *ai_next;		// Pointer to next in list. 
};
define in: /usr/include/netdb.h

The `socklen_t` defined: `unsigned int`. 

struct sockaddr {
	unsigned short sa_family;	// AF_****, etc.. 
	char sa_data[14];			// 14 bytes for Protocol Address
};
// define in: /usr/include/bits/socket.h

The `in_port_t` defined: `unsigned short`

struct sockaddr_in {
	short int		sin_family;	// Address Family: AF_INET, etc.. 
	in_port_t		sin_port;		// Port number. 
	struct in_addr	sin_addr;		// Internet address. 
	unsigned char	sin_zero[ \
		sizeof(struct sockaddr) - __SOCKADDR_COMMON_SIZE - sizeof(in_port_t) - sizeof(struct in_addr) \
	];
//	unsigned char	sin_zero[8];	// Pad to size of `struct sockaddr'.
};

struct sockaddr_in6 {
	uint16_t sin6_family;		// Address Family: AF_INET6, etc.. 
	in_port_t sin6_port;			// Transport layer port # 
	uint32_t sin6_flowinfo;		// IPv6 flow information 
	struct in6_addr sin6_addr;	// IPv6 address 
	uint32_t sin6_scope_id;		// IPv6 scope-id 
};

// define in: /usr/include/netinet/in.h

The `in_addr_t` defined: `unsigned int`

struct in_addr {
	in_addr_t s_addr;			// that's a 32-bit int (4 bytes) 
};

struct in6_addr {
	union {
		uint8_t	__u6_addr8[16];
#if defined __USE_MISC || defined __USE_GNU
		uint16_t	__u6_addr16[8];
		uint32_t	__u6_addr32[4];
#endif
	} __in6_u;
#define s6_addr		__in6_u.__u6_addr8
#if defined __USE_MISC || defined __USE_GNU
# define s6_addr16		__in6_u.__u6_addr16
# define s6_addr32		__in6_u.__u6_addr32
#endif
};
// define in: /usr/include/netinet/in.h

/usr/include/netinet/in.h: 
#define INET_ADDRSTRLEN		16
#define INET6_ADDRSTRLEN	46
*/

int main(void)
{
	int nStatus = 0, i = -1;
	struct addrinfo stAddrInfo;
	struct addrinfo *servinfo = (struct addrinfo *)NULL;
	struct addrinfo *pNext = (struct addrinfo *)NULL;
	struct sockaddr_in *pSockAddrIn = (struct sockaddr_in *)NULL;
	struct sockaddr_in6 *pSockAddrIn6 = (struct sockaddr_in6 *)NULL;
	char strIPv4Address[INET_ADDRSTRLEN];
	char strIPv6Address[INET6_ADDRSTRLEN];
	
	bzero((void *)&stAddrInfo, sizeof(struct addrinfo));
	stAddrInfo.ai_family = AF_UNSPEC;
	stAddrInfo.ai_socktype = SOCK_STREAM;
	stAddrInfo.ai_flags = AI_PASSIVE;

	nStatus = getaddrinfo("localhost", "8080", &stAddrInfo, &servinfo);
	if (nStatus == -1) {
		fprintf(stderr, "getaddrinfo() error: %s \n", gai_strerror(nStatus));
		exit(EXIT_FAILURE);
	}

	for (pNext = servinfo; pNext != (struct addrinfo *)NULL; pNext = pNext->ai_next) {
		printf("pNext->ai_flags = %d \n", pNext->ai_flags);
		printf("pNext->ai_family = %d \n", pNext->ai_family);
		printf("pNext->ai_socktype = %d \n", pNext->ai_socktype);
		printf("pNext->ai_protocol = %d \n", pNext->ai_protocol);
		printf("pNext->ai_addrlen = %d \n", (int)pNext->ai_addrlen);
		if (pNext->ai_family == AF_INET) {
			printf("pSockAddrIn = (struct sockaddr_in *)pNext->ai_addr; \n");
			pSockAddrIn = (struct sockaddr_in *)pNext->ai_addr;
			printf("pSockAddrIn->sin_family = %d \n", pSockAddrIn->sin_family);
			printf("pSockAddrIn->sin_port = %u \n", ntohs(pSockAddrIn->sin_port));
			memset(strIPv4Address, '\0', sizeof(char) * INET_ADDRSTRLEN);
			inet_ntop(pNext->ai_family, (void *)&pSockAddrIn->sin_addr, strIPv4Address, sizeof(char) * INET_ADDRSTRLEN);
			printf("pSockAddrIn->sin_addr = %s \n", strIPv4Address);
		}
		else if (pNext->ai_family == AF_INET6) {
			printf("pSockAddrIn6 = (struct sockaddr_in6 *)pNext->ai_addr; \n");
			pSockAddrIn6 = (struct sockaddr_in6 *)pNext->ai_addr;
			printf("pSockAddrIn6->sin6_family = %d \n", pSockAddrIn6->sin6_family);
			printf("pSockAddrIn6->sin6_port = %u \n", ntohs(pSockAddrIn6->sin6_port));
			printf("pSockAddrIn6->sin6_flowinfo = %d \n", pSockAddrIn6->sin6_flowinfo);
			memset(strIPv6Address, '\0', sizeof(char) * INET6_ADDRSTRLEN);
			inet_ntop(pNext->ai_family, (void *)&pSockAddrIn6->sin6_addr, strIPv6Address, sizeof(char) * INET6_ADDRSTRLEN);
			printf("pSockAddrIn6->sin6_addr = %s \n", strIPv6Address);
			printf("pSockAddrIn6->sin6_scope_id = %d \n", pSockAddrIn6->sin6_scope_id);
		}
		else { }
		printf("pNext->ai_canonname: %s \n", pNext->ai_canonname);
		printf("\n");
	}

	printf("sizeof(struct addrinfo) = %d \n", sizeof(struct addrinfo));
	printf("sizeof(struct in_addr) = %d \n", sizeof(struct in_addr));
	printf("sizeof(struct sockaddr) = %d \n", sizeof(struct sockaddr));
	printf("sizeof(struct sockaddr_in) = %d \n", sizeof(struct sockaddr_in));
	printf("sizeof(struct sockaddr_in6) = %d \n", sizeof(struct sockaddr_in6));
	printf("sizeof(struct sockaddr_storage) = %d \n", sizeof(struct sockaddr_storage));
	
	freeaddrinfo((void *)servinfo);

	return 0;
}
