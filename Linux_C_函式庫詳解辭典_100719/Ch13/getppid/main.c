#include <stdio.h>
#include <unistd.h>

int main(void) {	printf("My parent's PID = %d \n", (int)getppid());	return 0; }
