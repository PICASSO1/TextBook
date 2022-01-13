#include <stdlib.h>
#include <stdio.h>

void my_exit();

int main(void)
{
	atexit(my_exit);
	exit(0);

	return 0;
}

void my_exit(void)
{
	printf("before exit()! \n");

	return;
}
