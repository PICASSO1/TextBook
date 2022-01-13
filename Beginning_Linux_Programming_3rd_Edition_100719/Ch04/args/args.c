#include <stdio.h>

int 
main(argc, argv, envp)
int argc;
char **argv;
char *envp[];
{
	int arg = -1;

	for (arg = 0; arg < argc; arg++) {
		if (argv[arg][0] == '-')
			printf("option: %s \n", argv[arg] + 1);
		else
			printf("argument %d: %s \n", arg, argv[arg]);
	}

	return 0;
}
