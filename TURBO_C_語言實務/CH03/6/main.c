/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091822
 *
 * Date: 2022 / 09 / 18
 *
 * Description: 寫一程式以轉向方式讀入一文字檔，並且把其中小寫字母換成大寫字母 （反之亦然），再轉向輸出到一個新檔。
 *
(*)?*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define	IN_FILE		"PENIS"
#define	OUT_FILE	"ASSHOLE"

int main(void)
{
	FILE *fp_in = (FILE *)NULL, *fp_out = (FILE *)NULL;
	char cKey = '\0';

	fp_in = fopen(IN_FILE, "r");
	if (fp_in == (FILE *)NULL) {
		fprintf(stderr, "COULDN'T open the file: \"%s\" \n", IN_FILE);
		exit(EXIT_FAILURE);
	}

	fp_out = fopen(OUT_FILE, "w");
	if (fp_out == (FILE *)NULL) {
		fprintf(stderr, "COULDN'T create the file: \"%s\" \n", OUT_FILE);
		exit(EXIT_FAILURE);
	}

	cKey = fgetc(fp_in);
	while (cKey != EOF) {
		if (isupper(cKey) != 0)
			cKey += 0x20;
		else {
			if (islower(cKey) != 0)
				cKey -= 0x20;
		}
		fputc(cKey, fp_out);
		cKey = fgetc(fp_in);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}
