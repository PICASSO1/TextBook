#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid_tRet = vfork();

	if (pid_tRet == (pid_t)0) {
		printf("This is the child process!! \n");
		printf("vfork() = %d \n\n", (int)pid_tRet);
	}
	else	{
		printf("This is the parent process!! \n");
		printf("vfork() = %d \n", (int)pid_tRet);
	}

	return 0;
}
