#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>

int 
main(int argc, char *argv[], char **envp)
{
	int data_processed = 0;
	char buffer[BUFSIZ + 1];
	int file_descriptor = 0;

	memset(&buffer, '\0', sizeof(char) * (BUFSIZ + 1));
	sscanf(argv[1], "%d", &file_descriptor);
	data_processed = read(file_descriptor, &buffer, BUFSIZ);
	printf("%d - read %d bytes: %s \n", getpid(), data_processed, buffer);

	exit(EXIT_SUCCESS);
/*	return 0;	*/
}
