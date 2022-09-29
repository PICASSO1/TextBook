/**
 * File Name: my_exec.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092922
 *
 * Date: 2022 / 09 / 29
 *
 * Description: 請寫一程式 my_exec.c 來執行另一指定之程式，如：
 *              my_exec dir [ENTER]
 *              my_exec diskcopy [ENTER]
 *              會執行 dir 或 diskcopy 命令。請用 int86(); 或 intdos(); 不要用 spawn(); 。
 *
 * PS: 因為編譯時是 UNIX like OS (ubuntu 20.01.1)，所以並不會有 DOS 的相關指令 (dir, diskcopy)，更不會有其相關函式 (int86(); intdos(); spawn(); )；
 *     所以改用 Linux 平臺的相關指令 "ls -l", "cp -vf" 來驗證。
 *
(*)?*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define		CMD_SIZE		256

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	FILE *fp = (FILE *)NULL;
	char cmd[CMD_SIZE];
	size_t idx = 0U;

	memset(cmd, '\0', sizeof(char) * CMD_SIZE);
	for (idx = 1; idx < argc; idx++) {
		if (cmd[0] == '\0' && idx == 1)
			strncpy(cmd, argv[1], strlen(argv[1]));
		else {
			strcat(cmd, " ");
			strncat(cmd, argv[idx], strlen(argv[idx]));
		}
	}

	fp = popen(cmd, "w");
	if (fp == (FILE *)NULL) {
		fprintf(stderr, "The command: \"%s\" executed ERROR!! \n", cmd);
		exit(EXIT_FAILURE);
	}
	fclose(fp);

    return 0;
}
