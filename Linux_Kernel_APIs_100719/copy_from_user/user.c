#include "user.h"

int 
main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	int i = -1, fd = -1;
	unsigned char strDevFile[16];
	struct ioctl_cmd cmd;
	unsigned char ucTemp[32];

	if (argc < 2) {
		printf("Please input an argument (0~3)!! \n");
		exit(EXIT_FAILURE);
	}

	i = atoi(argv[1]);
	if (i < 0 || i > 3) {
		printf("The ERROR argument (%d)!! \n", i);
		exit(EXIT_FAILURE);
	}
	// 1. Open a Device File Description. 
	memset(strDevFile, '\0', sizeof(unsigned char) * 16);
	sprintf(strDevFile, "/dev/example%d", i);
	fd = open(strDevFile, O_RDWR);
	if (fd == -1) {
		perror("open");
		printf("errno: %d \n", errno);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("open():  %s \n", strDevFile);
	// 2. I/O Control File Description. 
	bzero(&cmd, sizeof(struct ioctl_cmd));
	cmd.val = 0xAA;
	i = ioctl(fd, IOCTL_VALSET, &cmd);
	if (i == -1) {
		perror("ioctl");
		printf("errno: %d \n", errno);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("ioctl(): cmd.val = 0x%02X \n", cmd.val);
	// 在執行ioctl()的時候，可以透過第3個參數傳給Kernel Space；也可以透過第3個參數Call by Reference回來！
	// 3. Write!!
	memset(ucTemp, '\0', sizeof(unsigned char) * 32);
	strcpy(ucTemp, "Hello!! World!! ");
	i = write(fd, ucTemp, strlen(ucTemp));
	if (i < 0) {
		perror("write");
		printf("errno: %d \n", errno);
		close(fd);
		exit(EXIT_FAILURE);
	}
	// 4. 再執行一次ioctl(). 
	cmd.val = 0xCC;
	i = ioctl(fd, IOCTL_VALGET, &cmd);
	if (i == -1) {
		perror("ioctl");
		printf("errno: %d \n", errno);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("ioctl(): cmd.val = 0x%02X \n", cmd.val);
	// 5. 把剛剛write()的資料讀回來確認！
	memset(ucTemp, '\0', sizeof(unsigned char) * 32);
	i = read(fd, ucTemp, sizeof(unsigned char) * 32);
	if (i < 0) {
		perror("write");
		printf("errno: %d \n", errno);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("read(): %s (%d) \n", ucTemp, strlen(ucTemp));
	// 6. Close File Description. 
	close(fd);
	
	return 0;
}
