#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	char *host = (char *)NULL, **names = (char **)NULL, **addrs = (char **)NULL; 
	struct hostent *hostinfo = (struct hostent *)NULL;

	/* 利用gethostname()函式取得Host名稱；或根據使用者來輸入 */
	if (argc == 1) {
		char myname[256];

		memset(myname, '\0', sizeof(char) * 256);
		gethostname(myname, 255);
		host = myname;
	}
	else 
		host = argv[1];
	/* 呼叫gethostbyname()；若無資訊就回報錯誤 */
	hostinfo = gethostbyname(host);
	if (hostinfo == (struct hostent *)NULL) {
		fprintf(stderr, "Cann't get info for host: %s \n", host);
		exit(EXIT_FAILURE);
	}
	/* 顯示主機名稱，還有它的可能別名 */
	printf("Result for host: %s \n", host);
	printf("Name      : %s \n", hostinfo->h_name);
	printf("Aliases   :");
	names = hostinfo->h_aliases;
	while (*names) {
		printf(" %s", *names);
		names++;
	}
	printf("\n");
	/* 如果主機並不是一個IP主機，顯示警告訊息且離開 */
	if (hostinfo->h_addrtype != AF_INET) {
		fprintf(stderr, "Not an IP Host!! \n");
		exit(EXIT_FAILURE);
	}
	/* 否則就顯示IP Address */
	printf("IP Address:");
	addrs = hostinfo->h_addr_list;
	while (*addrs) {
		printf(" %s", inet_ntoa(*(struct in_addr *)*addrs));
		addrs++;
	}
	printf("\n");

	return 0;
}
