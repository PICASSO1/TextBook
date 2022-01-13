#include <stdio.h>
#include <netinet/in.h>

/*
unsigned long int htonl(unsigned long int hostlong);
unsigned short int htons(unsigned short int hostshort);

unsigned long int ntohl(unsigned long int netlong);
unsigned short int ntohs(unsigned short int netshort);
*/

int main(void)
{
	unsigned long int ulnRet = 0U;
	unsigned short int uhnRet = 0U;
	/*
	IP Address: "192.168.1.1"
	Hex: 
	0xC0 (192), 0xA8 (168), 0x01 (1), 0x01 (1) --> 0xC0A80101
	Network Byte Order: 
	C0 A8 01 01會轉變為01 01 A8 C0 --> 0x0101A8C0 = 16885952
	*/
	ulnRet = htonl(0xC0A80101);
	printf("IP Address: %s (0xC0A80101); htonl(0xC0A80101): 0x%08X \n", "192.168.1.1", ulnRet);
	/*
	Port Number: 2048
	Hex: 2048 = 0x0800 (08 00)會轉變為0x0008 (00 08) = 8	
	*/
	uhnRet = htons(2048);
	printf("Port      : %s        (0x    0800); htons(0x    0800): 0x%08X \n", "2048", uhnRet);
	printf("\n");
	/*
	Network Byte Order: 16885952 (0x0101A8C0)
	Change to: 0xC0A80101 (192.168.1.1)
	*/
	ulnRet = ntohl(0x0101A8C0);
	printf("Network Byte Order: 0x0101A8C0; ntohl(0x0101A8C0): 0x%08X \n", ulnRet);
	/*
	Network Byte Order: 8 (0x0008)
	Change to: 0x0800 (2048)
	*/
	uhnRet = ntohs(8);
	printf("Network Byte Order: 0x00000008; ntohs(0x00000008): 0x%08X \n", uhnRet);

	return 0;
}
