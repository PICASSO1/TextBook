/**
 * File Name: my_grep.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092922
 *
 * Date: 2022 / 09 / 29
 *
 * Description: 增加上一題 (4)之程式功能，使 my_grep 時若加入 -e 參數，則 grep 由檔尾找起。
 *
 * PS: 1. sed 指令第一次執行的時候，有時後會出錯；但暫存檔 (*.bak)產生後，就沒有這個問題。
 *     2. "./my_grep -e "Jira" ./BULLSHIT -A" 反向搜尋的時候，順序經常會錯亂。。。。。。。。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	size_t idx = 0U;
	size_t flag_foreach = 0U;    /* for "-A" argument */
	size_t flag_reverse = 0U;    /* for "-e" argument */
	size_t flag_string = 0U;     /* for search string argument */
	size_t flag_file = 0U;       /* for file argument */
	char cmd[1024];
	FILE *fp = (FILE *)NULL;
	size_t lines = 0U;

	/* Check the command format: */
	/* Shorest: my_grep "Jira" ./BULLSHIT          ----> argc == 3 */
	/* Longest: my_grep -A -e "Jira" ./BULLSHIT    ----> argc == 5 */
	if (argc < 3 || argc > 5) {
		fprintf(stderr, "The command error!! \n");
		exit(EXIT_FAILURE);
	}

	/* Could we have any "-A" or "-e" arguments?? And decide which argument is file?? */
	for (idx = 1; idx < argc; idx++) {
		if (strncmp(argv[idx], "-A", (size_t)2) == 0) {
			flag_foreach = idx;
			continue;
		}
		else if (strncmp(argv[idx], "-e", (size_t)2) == 0) {
			flag_reverse = idx;
			continue;
		}
		else {
			if (access(argv[idx], F_OK | R_OK) == 0)
				flag_file = idx;
			else
				flag_string = idx;
		}
	}

	if (flag_file == 0) {
		fprintf(stderr, "The file DOESN'T exit or Permission Denied!! \n");
		exit(EXIT_FAILURE);
	}

	if (flag_reverse != 0)
		goto MDFK;

	if (flag_foreach != 0)
		execl("/usr/bin/grep", "grep", "-n", argv[flag_string], argv[flag_file], (char *)NULL);
	else
		execl("/usr/bin/grep", "grep", "-n", "-m", "1", argv[flag_string], argv[flag_file], (char *)NULL);

MDFK:
	memset(cmd, '\0', sizeof(char) * 1024);
	sprintf(cmd, "/usr/bin/grep -n %s %s 1> %s.bak", argv[flag_string], argv[flag_file], argv[flag_file]);
	fp = popen(cmd, "w");
	if (fp == (FILE *)NULL) {
		perror("MDFK!! \n");
		exit(EXIT_FAILURE);
	}

	memset(cmd, '\0', sizeof(char) * 1024);
	sprintf(cmd, "cat %s.bak | wc -l", argv[flag_file]);
	fp = popen(cmd, "r");
	if (fp == (FILE *)NULL) {
		perror("What's wrong with you?? \n");
		exit(EXIT_FAILURE);
	}
	memset(cmd, '\0', sizeof(char) * 1024);
	fread((void *)cmd, sizeof(char), 1024, fp);
	cmd[strlen(cmd)] = '\0';
	lines = atoi(cmd);

	if (flag_foreach != 0) {
		for (idx = lines; idx >= 1; idx--) {
			memset(cmd, '\0', sizeof(char) * 1024);
			sprintf(cmd, "/usr/bin/sed -n '%zup' %s.bak", idx, argv[flag_file]);
			fp = popen(cmd, "w");
			if (fp == (FILE *)NULL) {
				perror("");
				exit(EXIT_FAILURE);
			}
		}
	}
	else {
		memset(cmd, '\0', sizeof(char) * 1024);
		sprintf(cmd, "/usr/bin/sed -n '%zup' %s.bak", lines, argv[flag_file]);
		fp = popen(cmd, "w");
		if (fp == (FILE *)NULL) {
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	pclose(fp);

    return 0;
}
