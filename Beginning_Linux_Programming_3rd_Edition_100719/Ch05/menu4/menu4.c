#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>

/*
*	File Name: menu4.c
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
*	1. 
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
	struct termios initial_settings, new_settings;

	if (isatty(fileno(stdout)) != 1)
		fprintf(stderr, "You are not a terminal, OK!! \n");
	
	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");
	if ((input == NULL) || (output == NULL)) {
		fprintf(stderr, "Unable to open /dev/tty \n");
		fclose(input);
		fclose(output);
		exit(EXIT_FAILURE);
	}
	
	bzero((void *)&initial_settings, sizeof(struct termios));
	bzero((void *)&new_settings, sizeof(struct termios));
	tcgetattr(fileno(stdin), &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;
	if (tcsetattr(fileno(stdin), TCSANOW, &new_settings)!= 0 )
		fprintf(stderr, "Could not set attribute!! \n");
	
	do {
		choice = getchoice("Please select an action", menu, input, output);
		fprintf(stdout, "You have chosen: %c \n", choice);
	} while (choice != 'q');
	tcsetattr(fileno(input), TCSANOW, &initial_settings);
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
		} while (selected == '\n' || selected == '\r');

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
