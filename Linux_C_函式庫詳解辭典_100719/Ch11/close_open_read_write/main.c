#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd = -1, size = -2;
	char s[] = "Linux Programmer! \n", buffer[80];

	fd = open("/tmp/temp", O_WRONLY | O_CREAT, S_IRWXU);
	write(fd, s, sizeof(s));
	close(fd);

	fd = open("/tmp/temp", O_RDONLY);
	memset(&buffer, '\0', sizeof(char) * 80);
	size = read(fd, buffer, sizeof(char) * 80);
	close(fd);
	printf("%s, %d \n", buffer, size);

	return 0;
}
