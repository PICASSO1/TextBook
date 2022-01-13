#include <stdio.h>
#include <unistd.h>
#define SECONDS 5

int main(void)
{
	printf("Hello!! \n");
	sleep(SECONDS);
	printf("This program was delay %d seconds!! \n", SECONDS);
	printf("World!! \n");
	
	return 0;
}
