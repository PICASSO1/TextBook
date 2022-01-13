#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	unsigned char buf[4];
	int n = 0xDEADBEEF;

	memset(buf, 0x00, sizeof(unsigned char) * 4);
	memcpy(buf, &n, sizeof(unsigned char) * 4);
	printf("%02X %02X %02X %02X \n", buf[0], buf[1], buf[2], buf[3]);

	return 0;
}
