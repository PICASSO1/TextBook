/**
 * File Name: my_change.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092822
 *
 * Date: 2022 / 09 / 28
 *
 * Description: 寫一程式叫 my_change.c ，執行時：change string1 string2 file 會把 file 內所有的字串１換成字串２ (字串１與字串２不一定等長)。
 *
 * PS: "ASSHOLE", "BULLSHIT", "PENIS", "PUZZY" 這四個是用來「搜尋」的檔案；為了避免影響驗證，將取代結果導入到一個新檔案。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void usage(void)
{
	fprintf(stdout, "Usage: \n\n");
	fprintf(stdout, "my_change (source string) (target string) (file name) \n\n");
	fprintf(stdout, "Description: \n\n");
	fprintf(stdout, "This program will search \"source string\" in the file and replace them to \"target string\". \n\n");

	return;
}

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	char cmds[128], temp[32], src[32], target[32];
	FILE *fp = (FILE *)NULL;
	size_t j = 0U, k = 0U, len = 0U;

	if (argc != 4) {
		fprintf(stderr, "Format ERROR!! \n\n");
		usage();
		exit(EXIT_FAILURE);
	}

	if (access(argv[3], F_OK | R_OK) == -1) {
		fprintf(stderr, "The file %s DOESN'T exit or Permission Denied!! \n", argv[3]);
		exit(EXIT_FAILURE);
	}
	/* Check the input source string for ' ' character or not. */
	memset(temp, '\0', sizeof(char) * 32);
	len = strlen(argv[1]);
	for (j = 0; j < len; j++) {
		if (argv[1][j] == ' ') {
			temp[k++] = '\\';
			temp[k++] = ' ';
		}
		else
			temp[k++] = argv[1][j];
	}
	memset(src, '\0', sizeof(char) * 32);
	strncpy(src, temp, strlen(temp));
	/* Check the input target string for ' ' character or not. */
	memset(temp, '\0', sizeof(char) * 32);
	len = strlen(argv[2]);
	k = 0;	/* Need to initialize again. */
	for (j = 0; j < len; j++) {
		if (argv[2][j] == ' ') {
			temp[k++] = '\\';
			temp[k++] = ' ';
		}
		else
			temp[k++] = argv[2][j];
	}
	memset(target, '\0', sizeof(char) * 32);
	strncpy(target, temp, strlen(temp));

	memset(cmds, '\0', sizeof(char) * 128);
	sprintf(cmds, "/usr/bin/sed -e s/%s/%s/g %s 1> %s.bak", src, target, argv[3], argv[3]);
	fp = popen(cmds, "w");
	if (fp == (FILE *)NULL) {
		fprintf(stderr, "The command (%s) execute ERROR!! \n", cmds);
		exit(EXIT_FAILURE);
	}
	pclose(fp);

    return 0;
}
