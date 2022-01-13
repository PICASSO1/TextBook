#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

/*
struct protoent *getprotobyname(const char *name);
struct protoent *getprotobynumber(int proto);
struct protoent *getprotoent(void);
void endprotoent(void);

// / usr / include / netdb.h
struct protoent {
	char *p_name;	// Official protocol name. 
	char **p_aliases;	// Alias list. 
	int p_proto;		// Protocol number. 
};
*/

int main(void)
{
	struct protoent *p_stProtoent0 = (struct protoent *)NULL;
	struct protoent *p_stProtoent1 = (struct protoent *)NULL;
	struct protoent *p_stProtoent2 = (struct protoent *)NULL;
	int nIdx = -1;

	p_stProtoent0 = getprotobyname("l2tp");
	if (p_stProtoent0 == (struct protoent *)NULL) {
		herror("getprotobyname");
		return 1;
	}

	printf("getprotobyname(\"l2tp\"): \n");
	printf("Protocol Name  : %s \n", p_stProtoent0->p_name);
	nIdx = 0;
	printf("Alias List     : ");
	while (p_stProtoent0->p_aliases[nIdx] != (char *)NULL) {
		printf("%s \n", p_stProtoent0->p_aliases[nIdx++]);
	}
	printf("Protocol Number: %d \n", p_stProtoent0->p_proto);
	printf("\n");

	p_stProtoent1 = getprotobynumber(134);
	if (p_stProtoent1 == (struct protoent *)NULL) {
		herror("getprotobynumber");
		return 1;
	}

	printf("getprotobynumber(134): \n");
	printf("Protocol Name  : %s \n", p_stProtoent1->p_name);
	nIdx = 0;
	printf("Alias List     : ");
	while (p_stProtoent1->p_aliases[nIdx] != (char *)NULL) {
		printf("%s \n", p_stProtoent1->p_aliases[nIdx++]);
	}
	printf("Protocol Number: %d \n", p_stProtoent1->p_proto);
	printf("\n");

	printf("getprotoent(): \n");
	while (p_stProtoent2 = getprotoent()) {
		printf("%-16s %-4d %-16s \n", p_stProtoent2->p_name, p_stProtoent2->p_proto, p_stProtoent2->p_aliases[0]);
	}
	endprotoent();

	return 0;
}
