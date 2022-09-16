/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091522
 *
 * Date: 2022 / 09 / 15
 *
 * Description: 寫一程式以 (f)scanf(); 讀入任意字串，在每個字元間插入一空格，然後印出來。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

#define	MAX_LEN	1024

int main(void)
{
	char strTemp[MAX_LEN];
	int idx = 0;
	size_t len = 0U;

	memset(strTemp, '\0', sizeof(char) * MAX_LEN);
	fprintf(stdout, "Please input a string, maximum length is %d: ", MAX_LEN);
	fscanf(stdin, "%s", strTemp);

	len = strlen(strTemp);
	fprintf(stdout, "Your input: %s (%zu); and the result is: \n", strTemp, len);

	for (idx = 0; idx < len; idx++)
		fprintf(stdout, "%c ", strTemp[idx]);
	puts("");

	return 0;
}
