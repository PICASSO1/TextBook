/**
 * File Name: my_echo.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092522
 *
 * Date: 2022 / 09 / 25
 *
 * Description: 試寫一個叫 my_echo 的程式，鍵入 my_echo xxx.... 時能把 my_echo 後面字串回映至螢幕，而若鍵入 my_echo -n xxx.... ，
 *              則印出所鍵入之字元個數 (不含 my_echo、-n及空白)。
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	size_t flag = 0U, idx = 0U, cnt = 0U;

	for (idx = 1; idx < argc; idx++) {
		if (strncmp(argv[idx], "-n", 2) == 0)
			flag = 1;
	}

	for (idx = 1; idx < argc; idx++) {
		if (strncmp(argv[idx], "-n", 2) != 0) {
			fprintf(stdout, "%s (%zu) \n", argv[idx], strlen(argv[idx]));
			cnt += strlen(argv[idx]);
		}
	}

	if (flag == 1)
		fprintf(stdout, "The total characters were: %zu \n", cnt);

    return 0;
}
