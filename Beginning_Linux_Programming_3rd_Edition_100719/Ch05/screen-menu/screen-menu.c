#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <term.h>
#include <curses.h>

/*
*	File Name: screen-menu.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030116
*
*	Date: 2016 / 03 / 01
*
*	Description: 
*	1. 
*	2. 
*/

static FILE *output_stream = (FILE *)NULL;

char *menu[] = {
	"a - add new record", 
	"d - delete record",
	"q - quit",
	NULL
};

int getchoice(char *, char *[], FILE *, FILE *);
int char_to_terminal(int);

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
		sleep(1);
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
	int chosen = 0, selected = 0, screenrow = 0, screencol = 10;

	char **option = (char **)NULL, *cursor = (char *)NULL, *clear = (char *)NULL;

	output_stream = out;

	setupterm(NULL, fileno(out), (int *)NULL);
	cursor = tigetstr("cup");
	clear = tigetstr("clear");

	screenrow = 4;
	tputs(clear, 1, char_to_terminal);
	tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
	fprintf(out, "Choice: %s", greet);
	screenrow += 2;
	option = choices;
	while (*option) {
		tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
		fprintf(out, "%s", *option);
		screenrow++;
		option++;
	}
	fprintf(out, "\n");

	do {
		fflush(out);
		selected = fgetc(in);
		option = choices;
		while (*option) {
			if (selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}
		if (!chosen) {
			tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
			fprintf(out, "Incorrect choice, select again!! \n");
		}
	} while (!chosen);
	tputs(clear, 1, char_to_terminal);

	return selected;
}

int 
char_to_terminal(char_to_write)
int char_to_write;
{
	if (output_stream != (FILE *)NULL)
		putc(char_to_write, output_stream);

	return 0;
}
