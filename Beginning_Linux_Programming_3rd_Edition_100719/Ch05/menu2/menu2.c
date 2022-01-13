#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: menu2.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022416
*
*	Date: 2016 / 02 / 24
*
*	Description: 
*	1. 這一支程式主要是在介紹"isatty()"函式的用法；此一範例 ---- (isatty(fileno(stdout)) != 1)，檢查標準輸出 (stdout)是否為一個終端機!!
*/

char *menu[] = {
	"a - add new record", 
	"d - delete record",
	"q - quit",
	(char *)NULL
};

int getchoice(char *, char *[]);

int 
main()
{
	int choice = 0;

	if (isatty(fileno(stdout)) != 1) {
		fprintf(stderr, "You are not a terminal!! \n");
		exit(EXIT_FAILURE);
	}
	
	do {
		choice = getchoice("Please select an action", menu);
		printf("You have chosen: %c \n", choice);
	} while (choice != 'q');

	return 0;
}

int 
getchoice(greet, choices)
char *greet;
char *choices[];
{
	int chosen = 0, selected = 0;
	char **option = (char **)NULL;

	do {
		printf("Choice: %s \n", greet);
		option = choices;

		while (*option) {
			printf("%s \n", *option);
			option++;
		}

		selected = getchar();
	/*	do {
			selected = getchar();
		} while (selected == '\n');
	*/	option = choices;

		while (*option) {
			if (selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}

		if (!chosen)
			printf("Incorrect choice, select again. \n");
	} while (!chosen);


	return selected;
}
