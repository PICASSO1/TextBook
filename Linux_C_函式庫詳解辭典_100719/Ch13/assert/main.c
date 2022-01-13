#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	assert(open("/tmp/noexist", O_RDONLY) >= 0);
	printf("open OK!! \n");

	return 0;
}
