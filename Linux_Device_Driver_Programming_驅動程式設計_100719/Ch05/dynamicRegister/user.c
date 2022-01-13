#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd[DEVCOUNT], i = -1;
	char file[BUFSIZ];

	for (i = 0; i < DEVCOUNT; i++) {
		snprintf(file, sizeof(char) * BUFSIZ, "%s%d", DEVFILE, i);
		printf("%s \n", file);
		fd[i] = open_file(file);
	}
	sleep(3);
	for (i = 0; i < DEVCOUNT; i++) {
		printf("Closing fd[%d] = %d.  \n", i, fd[i]);
		close_file(fd[i]);
	}

	showDmesg();

	return 0;
}
