#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t n = (pid_t)0;

	n = getpid();
	printf("Do you know?? What's the \"PROCESS\"?? \n");
	printf("It'll be create a process when the program was running!! \n");
	sleep(10);
	printf("For instance, this program is process, and this process ID was %d \n", n);

	return 0;
}
