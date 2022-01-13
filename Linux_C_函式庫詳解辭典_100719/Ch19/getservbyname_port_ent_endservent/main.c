#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

/*
struct servent *getservbyname(const char *name, const char *proto);
struct servent *getservbyport(int port, const char *proto);
struct servent *getservent(void);
void endservent(void);

// / usr / include / netdb.h
struct servent {
	char *s_name;	// Official service name. 
	char **s_aliases;	// Alias list. 
	int s_port;		// Port number. 
	char *s_proto;	// Protocol to use. 
};
*/

int main(void)
{
	struct servent *p_stServent0 = (struct servent *)NULL;
	struct servent *p_stServent1 = (struct servent *)NULL;
	struct servent *p_stServent2 = (struct servent *)NULL;
	int nIdx = -1;

	p_stServent0 = getservbyname("telnet", "tcp");
	if (p_stServent0 == (struct servent *)NULL) {
		herror("getservbtname");
		return 1;
	}

	printf("getservbyname(\"telnet\", \"tcp\"): \n");
	printf("Service Name: %s \n", p_stServent0->s_name);
	nIdx = 0;
	printf("Alias List  : \n");
	while (p_stServent0->s_aliases[nIdx] != (char *)NULL) {
		printf("%s \n", p_stServent0->s_aliases[nIdx++]);
	}
	printf("Port Number : %d \n", ntohs(p_stServent0->s_port));
	printf("Protocol    : %s \n", p_stServent0->s_proto);
	printf("\n");

	p_stServent1 = getservbyport(htons(23), "udp");
	if (p_stServent1 == (struct servent *)NULL) {
		herror("getservbyport");
		return 1;
	}

	printf("getservbyport(htons(23), \"udp\"): \n");
	printf("Service Name: %s \n", p_stServent1->s_name);
	nIdx = 0;
	printf("Alias List  : \n");
	while (p_stServent1->s_aliases[nIdx] != (char *)NULL) {
		printf("%s \n", p_stServent1->s_aliases[nIdx++]);
	}
	printf("Port Number : %d \n", ntohs(p_stServent1->s_port));
	printf("Protocol    : %s \n", p_stServent1->s_proto);
	printf("\n");

	printf("getservent(): \n");
	while (p_stServent2 = getservent()) {
		printf("%-16s, %d/%s \n", p_stServent2->s_name, ntohs(p_stServent2->s_port), p_stServent2->s_proto);
	}
	endservent();

	return 0;
}
