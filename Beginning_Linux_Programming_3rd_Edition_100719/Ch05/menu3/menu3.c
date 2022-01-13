#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
*	File Name: menu3.c
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
*	1. 此一程序的用法為：./menu3 1> ./file0 2> ./file1; 再分別去檢視file0, file1看看差異再哪裡！！
*	2. 
*/

char *menu[] = {
	"a - add new record", 
	"d - delete record",
	"q - quit",
	NULL
};

int getchoice(char *, char *[], FILE *, FILE *);

int 
main()
{
	int choice = 0;
	FILE *input = (FILE *)NULL, *output = (FILE *)NULL;

	if (!isatty(fileno(stdout)))
		fprintf(stderr, "You are not a terminal, OK!! \n");
	
	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
	if ((input == NULL) || (output == NULL)) {
		fprintf(stderr, "Unable to open /dev/tty \n");
		fclose(input);
		fclose(output);
		exit(EXIT_FAILURE);
	}
	
	do {
		choice = getchoice("Please select an action", menu, input, output);
		fprintf(stdout, "You have chosen: %c \n", choice);
	} while (choice != 'q');

	fclose(input);
	fclose(output);

	return 0;
}

int 
getchoice(greet, choices, in, out)
char *greet;
char *choices[];
FILE *in, *out;
{
	int chosen = 0, selected = 0;
	char **option = (char **)NULL;

	do {
		fprintf(out, "Choice: %s \n", greet);
		option = choices;

		while (*option) {
			fprintf(out, "%s \n", *option);
			option++;
		}
		
		do {
			selected = fgetc(in);
		} while (selected == '\n');

		option = choices;

		while (*option) {
			if (selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}

		if (!chosen)
			fprintf(out, "Incorrect choice, select again. \n");
	} while (!chosen);

	return selected;
}
