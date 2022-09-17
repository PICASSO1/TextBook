/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091622
 *
 * Date: 2022 / 09 / 16
 *
 * Description: 寫一程式用轉向讀入一文字檔，並計算出檔案內的字 (word)數。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>

int main(argc, argv, envp)
int argc;
char *argv[];
char **envp;
{
	FILE *fp = (FILE *)NULL;
	char cKey = '\0';
	unsigned int cnt = 0U;

	if (argc < 2) {
		perror("Please input a file!! \n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == (FILE *)NULL) {
		fprintf(stderr, "COULDN'T open the file: \"%s\" \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	cKey = fgetc(fp);
	while (cKey != EOF) {
		fputc(cKey, stdout);
		fprintf(stdout, " (0x%02X)", (int)cKey);
		cnt++;
		cKey = fgetc(fp);
	}

	fprintf(stdout, "\nTotal characters: %u \n", cnt);

	fclose(fp);

	return 0;
}
