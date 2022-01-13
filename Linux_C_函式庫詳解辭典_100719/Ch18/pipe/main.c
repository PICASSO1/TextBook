#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

int 
main(void)
{
	int fd[2];
	char buffer[80];
	char s[] = "Hello!! World!! \n";

	bzero((void *)&fd, sizeof(int) * 2);
	pipe(fd);
	if (fork() == 0) {
		read(fd[0], (void *)&buffer, sizeof(char) * 80);
		printf("buffer: %s \n", buffer);
	}
	else
		write(fd[1], (void *)&s, (size_t)strlen(s));

	return 0;
}
