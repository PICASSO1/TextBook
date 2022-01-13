#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	int nRet = 1;

	if ( argc < 3 ) {
		printf("Please enter an old name and a new name!! \n");
		exit(0);
	}

	nRet = rename(argv[1], argv[2]);
	if ( nRet != 0 ) {
		perror("rename");
	}
	system("ls -l");

	return 0;
}
