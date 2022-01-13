#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/*
*	File Name: subsc1.c
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

int 
main()
{
	WINDOW *sub_window_ptr = (WINDOW *)NULL;
	int x_loop = -1, y_loop = -1, counter = 0;
	char a_letter = '1';

	initscr();
	for (y_loop = 0; y_loop < (LINES - 1); y_loop++) {
		for (x_loop = 0; x_loop < (COLS - 1); x_loop++) {
			mvwaddch(stdscr, y_loop, x_loop, a_letter);
			a_letter++;
			if (a_letter > '9')
				a_letter = '1';
		}
		if (a_letter > 'Z')
			a_letter = 'A';
	}
	sub_window_ptr = subwin(stdscr, 10, 20, 10, 10);
	scrollok(sub_window_ptr, 1);
	touchwin(stdscr);
	refresh();
	sleep(1);

	werase(sub_window_ptr);
	mvwprintw(sub_window_ptr, 2, 0, "%s", "This window will now scroll. ");
	wrefresh(sub_window_ptr);
	sleep(1);
	for (counter = 1; counter < 10; counter++) {
		wprintw(sub_window_ptr, "%s", "This text is both wrapping and scrolling. ");
		wrefresh(sub_window_ptr);
		sleep(1);
	}

	delwin(sub_window_ptr);

	touchwin(stdscr);
	refresh();
	sleep(1);

	endwin();

	return 0;
}
