#include <stdio.h>
#include <unistd.h>
#define SECONDS 5

int main(void)
{
	printf("Hello!! \n");
	usleep(SECONDS * 1000000);
	printf("This program was delay %d micro-seconds!! \n", SECONDS * 1000000);
	printf("World!! \n");
	
	return 0;
}
