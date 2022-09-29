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
 * Description: 4. 寫一程式叫 my_grep.c 可以由程式中找出指字之字串：
 *                 my_grep "you" file        ---->    會把 file 內含有 "you" 的第一行字串印出來
 *                 my_grep -A "you" file    ---->    會把 file 內含有 "you" 的每一行字串印出來
 *                 列印時，每行前頭要加印行號 (如：12: you are luck)。
 *
 * PS: 搜尋字串： "Jira" ；驗證檔案： "BULLSHIT"
 *     這只是很單純地 C 語言練習，並不想使用 getopt(); & getopt_long(); 等函式。
 *     格式：my_grep (要搜尋的字串) (要被搜尋的檔案) ；"-A" & "-e" 在哪兒都無所謂，「字串參數」要在「檔案參數」的前面。
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

	if (flag_foreach != 0)
		execl("/usr/bin/grep", "grep", "-n", argv[flag_string], argv[flag_file], (char *)NULL);
	else
		execl("/usr/bin/grep", "grep", "-n", "-m", "1", argv[flag_string], argv[flag_file], (char *)NULL);

    return 0;
}
