#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>

int 
main()
{
	pid_t pid = 1;
	int fd[2], nRet = 0;
	char szSend[16], szRecv[32];

	bzero((void *)&fd, sizeof(int) * 2);
	if (pipe(fd) != 0) {
		perror("Create pipe() failed (error)!! \n");
		exit(EXIT_FAILURE);
	}
//	printf("fd[0] = %d; fd[1] = %d \n", fd[0], fd[1]);
	memset(&szSend, '\0', sizeof(char) * 16);
	pid = fork();
	if (pid == 0) {
		close(STDIN_FILENO);

		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);

		strcpy(szSend, "Hello!! ");
		write(STDOUT_FILENO, (void *)szSend, strlen(szSend));
		exit(EXIT_SUCCESS);
	}
	waitpid(0, &nRet, 0);

	dup2(fd[0], STDIN_FILENO);
//	close(STDOUT_FILENO);	// Don't close it!!
	close(fd[0]);
	close(fd[1]);

	memset(&szRecv, '\0', sizeof(char) * 32);
	read(STDIN_FILENO, (void *)szRecv, sizeof(char) * 32);
	strcat(szRecv, "World!! ");
	printf("szRecv: %s (%d) \n", szRecv, strlen(szRecv));
	
	return 0;
}
