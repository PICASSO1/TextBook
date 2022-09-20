/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092022
 *
 * Date: 2022 / 09 / 20
 *
 * Description: 寫一輸入 password 的程式。
 *
(*)?*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define	PWD_LEN	16

void main(void)
{
	const char *passwd = "password";
	char *ptr = (char *)malloc(sizeof(char) * PWD_LEN);

	if (ptr == (char *)NULL) {
		perror("Allocate memory failed!! ");
		exit(EXIT_FAILURE);
	}

	ptr = getpass("Please input your password: ");
	while (strncmp(passwd, ptr, strlen(passwd)) != 0) {
		fprintf(stderr, "Incorrect!! \n");
		ptr = getpass("Please input your password: ");
	}
	fprintf(stdout, "Correct!! \n");

	return;
}
