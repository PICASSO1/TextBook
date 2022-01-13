#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
//#include <term.h>
#include <curses.h>

/*
*	File Name: kbhit.c
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

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard();
void close_keyboard();
int kbhit();
int readch();

int 
main()
{
	int ch = 0;

	init_keyboard();
	while (ch != 'q') {
		printf("Looping \n");
		sleep(1);
		if (kbhit()) {
			ch = readch();
			printf("You hit 0x%02X \n", ch);
		}
	}
	close_keyboard();

	return 0;
}

void 
init_keyboard()
{
	bzero((void *)&initial_settings, sizeof(struct termios));
	tcgetattr(0, &initial_settings);
	bzero((void *)&new_settings, sizeof(struct termios));
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &new_settings);

	return;
}

void 
close_keyboard()
{
	tcsetattr(0, TCSANOW, &initial_settings);

	return;
}

int 
kbhit()
{
	char ch = '\0';
	int nread = 0;

	if (peek_character != -1)
		return 1;

	new_settings.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &new_settings);
	nread = read(0, &ch, 1);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);

	if (nread == 1) {
		peek_character = ch;
		return 1;
	}

	return 0;
}

int 
readch()
{
	char ch = '\0';

	if (peek_character != -1) {
		ch = peek_character;
		peek_character = -1;
		return ch;
	}
	read(0, &ch, 1);

	return;
}
