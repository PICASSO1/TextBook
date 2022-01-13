#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int nRet = 1;

	if (argc != 2) {
		printf("Please input a file name!! \n");
		return 0;
	}

	nRet = access(argv[1], R_OK);
	if (nRet == 0)
		printf("%s file can be read!! \n", argv[1]);
	else
		printf("%s file can't read!! \n", argv[1]);

	return 0;
}
