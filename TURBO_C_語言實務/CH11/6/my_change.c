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
	char cmds[128], temp[64];
	FILE *fp = (FILE *)NULL;
	size_t j = 0U, k = 0U, len = 0U;
/*
	if (argc != 4) {
		fprintf(stderr, "Format ERROR!! \n\n");
		usage();
		exit(EXIT_FAILURE);
	}

	if (access(argv[3], F_OK | R_OK) == -1) {
		fprintf(stderr, "The file %s DOESN'T exitm or Permission Denied!! \n", argv[3]);
		exit(EXIT_FAILURE);
	}
*/
	/* Check the input string for ' ' character or not. */
	memset(temp, '\0', sizeof(char) * 64);
	len = strlen(argv[1]);
	for (j = 0; j < len; j++) {
		if (argv[1][j] == ' ') {
			temp[k] = '\\';
			k++;
			temp[k] = ' ';
			k++;
		}
		else {
			temp[k] = argv[1][j];
			k++;
		}
	}
	printf("MDFK: argv[1]: %s; %s (%zu) \n", argv[1], temp, strlen(temp));

	memset(cmds, '\0', sizeof(char) * 128);
	sprintf(cmds, "/usr/bin/sed -e %s 1> %s.bak", argv[3], argv[3]);
//	fp = popen("/usr/bin/sed -e s/my\\ skin/GGGG\\ FFFF/g PUZZY 1> ./MDFK", "w");	// This command is fine!! 
//	fclose(fp);

    return 0;
}
