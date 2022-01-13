#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int fd = -1, i = -1;

	for (i = 0; i < 2; i++) {
		printf("No. %d \n", i + 1);

		fd = open_file(DEVFILE);

		read_file(fd);

		write_file(fd, 0x00);
		read_file(fd);
		
		write_file(fd, 0xC0);
		read_file(fd);
		
		close_file(fd);
	}

	showDmesg();

	return 0;
}
