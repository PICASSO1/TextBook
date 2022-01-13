/**
* File Name: $(shell pwd)/Linux_User_API/Ch13/waitpid/main.c
*
* CopyLeft (C) 2015-2016, Picasso's Fantasy Notepad. All rights reserved.
*
* Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
* Version: 0.0.0.build102915
*
* Date: 2015 / 10 / 29
*
* Description: 
* 1. You could command: "./main", and wait for twenty seconds, you can get WIFEXITED(), WEXITSTATUS() resultl;
* 2. You can get WIFSIGNALED(), WTERMSIG result, if you input "kill -s SIGHUP (CPID)" on the other command window!!
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/wait.h>
#include <signal.h>

int 
main()
{
	pid_t pid = -2, PPID = -3, CPID = -4;
	int nStatus = 0, _Exit = 0;

	pid = fork();
	if (pid == 0) {
		signal(SIGHUP, SIG_DFL);
		CPID = getpid();
		PPID = getppid();
		printf("\nChild (PPID / CPID): %d / %d \n", PPID, CPID);
		usleep(10 * 1000000);
		exit(EXIT_SUCCESS);
	}

	PPID = getpid();
	sleep(20);
	CPID = waitpid(-1, &nStatus, WNOHANG);
	printf("Parent (PPID / CPID): %d / %d \n", PPID, CPID);
/*	printf ("nStatus = %d \n", nStatus);
	printf("WIFEXITED() = %d; WEXITSTATUS() = %d \n", WIFEXITED(nStatus), WEXITSTATUS(nStatus));
	printf("WIFSIGNALED() = %d; WTERMSIG() = %d \n", WIFSIGNALED(nStatus), WTERMSIG(nStatus));
	printf("WIFSTOPPED() = %d; WSTOPSIG() = %d \n", WIFSTOPPED(nStatus), WSTOPSIG(nStatus));
*/	if (WIFEXITED(nStatus) != 0) {
		_Exit = WEXITSTATUS(nStatus);
		switch (_Exit) {
			default:
				printf("The Child Process EXIT-STATUS code: %d \n\n", _Exit);
				break;
		}
	}
	else if (WIFSIGNALED(nStatus) != 0) {
		_Exit = WTERMSIG(nStatus);
		switch (_Exit) {
			default:
				printf("The Child Process TERMINAL-SIGNAL code: %d \n\n", _Exit);
				break;
		}
	}
/*	else if (WIFSTOPPED(nStatus) != 0) {
		_Exit = WSTOPSIG(nStatus);
		switch (_Exit) {
			default:
				printf("The Child Process STOP-SIGNAL code: %d \n", _Exit);
				break;
		}
	}
*/	else
		printf("Child terminated abnormally. \n");

	return 0;
}
