#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022616
*
*	Date: 2016 / 02 / 26
*
*	Description: 
*	1. getpriority()和setpriority()函式，是可以從自己這一支程序 (行程)，去修改別支程序 (行程)的優先權！
*	2. 參數的對應如下：
*		PRIO_PROCESS ----> (pid_t)
*		PRIO_PGRP        ----> (gid_t)
*		PRIO_USER        ----> (uid_t)
*/

int 
main()
{
	int nPriority = 0;
	int nPid = (unsigned int)getpid();

	// Get original process priority ....
	nPriority = getpriority(PRIO_PROCESS, nPid);
	if (nPriority == -1) {
		perror("getpriority");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Before, this process priority is: %d \n", nPriority);

	// Set a new priority ....
	nPriority = setpriority(PRIO_PROCESS, nPid, -10);
	if (nPriority == -1) {
		perror("setpriority");
		exit(EXIT_FAILURE);
	}

	// Get original process priority ....
	nPriority = getpriority(PRIO_PROCESS, nPid);
	if (nPriority == -1) {
		perror("getpriority");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "After, this process priority is: %d \n", nPriority);

	return 0;
}
