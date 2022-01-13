#include "include.h"
#include "declare.h"
#include "define.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	struct ioctl_cmd cmd;
	int ret = -1, fd = -1;

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	bzero((void *)&cmd, sizeof(struct ioctl_cmd));
	ret = ioctl(fd, IOCTL_VALGET, &cmd);
	if (ret == -1) {
		printf("errno: %d \n", errno);
		perror("ioctl");
	}
	printf("val: %d \n", cmd.val);			// 因為在open() / devone_open()時，val的值被塞0xFF (255)，所以印出來的值是255
	// read buffer
	read_buffer(fd);					// 這裡會列印出64個0xFF；這些值是在open() / devone_open()時就填入的！

	bzero((void *)&cmd, sizeof(struct ioctl_cmd));
	cmd.val = 0xCC;
	ret = ioctl(fd, IOCTL_VALSET, &cmd);	// 透過ioctl()，把0xCC的值送到Kernel Space. 
	if (ret == -1) {
		printf("errno: %d \n", errno);
		perror("ioctl");
	}
	// read buffer
	read_buffer(fd);					// 這裡會列印出64個0xCC；這些值是在ioctl( , IOCTL_VALSET, )時填入的。

	bzero((void *)&cmd, sizeof(struct ioctl_cmd));
	ret = ioctl(fd, IOCTL_VALGET, &cmd);
	if (ret == -1) {
		printf("errno: %d \n", errno);
		perror("ioctl");
	}
	printf("val: %d \n", cmd.val);			// 因為在ioctl( , IOCTL_VALSET, )時，val的值被塞0xCC (204)，所以印出來的值是204

	close(fd);

	return 0;
}
