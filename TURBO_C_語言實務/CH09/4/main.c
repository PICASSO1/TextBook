/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092522
 *
 * Date: 2022 / 09 / 25
 *
 * Description: 
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t isInteger(char *);

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	int retval = 0;

	if (argc == 1 || argc > 2) {
		fprintf(stderr, "NULL input!! Please input an integer!! \n");
		exit(EXIT_FAILURE);
	}

	if (isInteger(argv[1]) != 0) {
		fprintf(stderr, "ERROR!! Please input an integer!! \n");
		exit(EXIT_FAILURE);
	}

	retval = atoi(argv[1]);
	if (retval > 0)
		fprintf(stdout, "The number %s is a Positive!! \n", argv[1]);
	else if (retval < 0)
		fprintf(stdout, "The number %s is a Negative!! \n", argv[1]);
	else if (retval == 0)
		fprintf(stdout, "The number %s is a ZERO!! \n", argv[1]);
	else
		fprintf(stdout, "MDFK!! Unknown value: %s \n", argv[1]);

	if ((retval % 2) == 0)
		fprintf(stdout, "The number %s is a Even!! \n", argv[1]);
	else
		fprintf(stdout, "The number %s is a Odd!! \n", argv[1]);

    return 0;
}

size_t 
isInteger(str)
char *str;
{
	size_t len = strlen(str), idx = 0U, flag = 0U;

	for (idx = 0; idx < len; idx++) {
		if (*(str + idx) < '0' || *(str + idx) > '9') {
			if (*(str + idx) != '-' && *(str + idx) != '.') {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
