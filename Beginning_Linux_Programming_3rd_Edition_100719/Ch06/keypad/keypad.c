#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/*
*	File Name: keypad.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build031516
*
*	Date: 2016 / 03 / 15
*
*	Description: 
*	1. 
*/

#define	LOCAL_ESCAPE_KEY		27

int 
main()
{
	char key = '\0';

	initscr();
	crmode();
	keypad(stdscr, TRUE);

	noecho();
	clear();
	mvprintw(5, 5, "Key pad demonstration. Press 'q' to quit. ");
	move(7, 5);
	refresh();
	key = getch();
	while ((key != ERR) && (key != 'q')) {
		move(7, 5);
		clrtoeol();
		if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))
			printw("Key was %c", key);
		else {
			switch (key) {
				case LOCAL_ESCAPE_KEY: 
					printw("%s", "Escape key");
					break;
				case KEY_END: 
					printw("%s", "END key");
					break;
				case KEY_BEG: 
					printw("%s", "Bikini key");
					break;
				case KEY_RIGHT: 
					printw("%s", "RIGHT key");
					break;
				case KEY_LEFT: 
					printw("%s", "LEFT key");
					break;
				case KEY_UP: 
					printw("%s", "UP key");
					break;
				case KEY_DOWN: 
					printw("%s", "DOWN key");
					break;
				default:
					printw("Unmatched - %d", key);
					break;
			}
		}
		refresh();
		key = getch();
	}
	endwin();

	return 0;
}
