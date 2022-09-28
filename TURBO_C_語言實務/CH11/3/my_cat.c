/**
 * File Name: my_cat.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092822
 *
 * Date: 2022 / 09 / 28
 *
 * Description: 寫一程式叫 my_cat.c 可以一次列印多個檔案：cat file1 file2 file3 .... 會把 file1 列印完接著列印 file2 ，接著 file3。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BUFFER_SIZE		1024

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	FILE *fp =(FILE *)NULL;
	int idx = 0;
	char buffer[BUFFER_SIZE];

	for (idx = 1; idx < argc; idx++) {
		fp = fopen(argv[idx], "r");
		if (fp == (FILE *)NULL) {
			fprintf(stderr, "\nCOULDN'T open the file: %s \n", argv[idx]);
			continue;
		}

		fprintf(stdout, "\n%s: \n\n", argv[idx]);
		memset(buffer, '\0', sizeof(char) * BUFFER_SIZE);
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
			buffer[strlen(buffer)] = '\0';
			fputs(buffer, stdout);
		}
	}

	if (fp != (FILE *)NULL)
		fclose(fp);

    return 0;
}
