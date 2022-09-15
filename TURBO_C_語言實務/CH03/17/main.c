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
 * Description: 寫一程式把輸入之字串倒著印出來。
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
	printf("Please input a string, maximum length is %d: ", MAX_LEN);
	fscanf(stdin, "%s", strTemp);

	len = strlen(strTemp);
	fprintf(stdout, "Your input: %s (%zu); and .... \n", strTemp, len);

	for (idx = --len; idx >= 0; idx--)
		fprintf(stdout, "%c", strTemp[idx]);
	puts("");

	return 0;
}
