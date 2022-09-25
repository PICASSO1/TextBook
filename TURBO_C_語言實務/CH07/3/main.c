/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092322
 *
 * Date: 2022 / 09 / 23
 *
 * Description: 用函式的寫法將鍵盤輸入的兩個數當作引述比較大小，並 return 值給主程式，印出數目較大者。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t isInteger(char *);
int MAX(int, int);

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	if (argc != 3) {
		fprintf(stderr, "ERROR!! Please enter two intergers!! \n");
		exit(EXIT_FAILURE);
	}
	
	if (isInteger(argv[1]) != 0 || isInteger(argv[2]) != 0) {
		fprintf(stderr, "ERROR!! Please enter two intergers!! \n");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "You input %d intergers, 1st is: %s; 2nd is: %s; and the Maximum one is: %d\n", \
		argc - 1, argv[1], argv[2], MAX(atoi(argv[1]), atoi(argv[2])));

	return 0;
}

size_t 
isInteger(str)
char *str;
{
	size_t len = strlen(str), idx = 0U, flag = 0U;

	for (idx = 0; idx < len; idx++) {
		if (*(str + idx) < '0' || *(str + idx) > '9') {
			if (*(str + idx) != '-') {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

int 
MAX(one, two)
int one, two;
{
	return (one > two)? one: two;
}
