#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/*
*	File Name: pad.c
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
	WINDOW *pad_ptr = (WINDOW *)NULL;
	int x = -1, y = -1, pad_lines = -1, pad_cols = -1;
	char disp_char = '\0';

	initscr();
	pad_lines = LINES + 50;
	pad_cols = COLS + 50;
	pad_ptr = newpad(pad_lines, pad_cols);
	disp_char = 'a';

	for (x = 0; x < pad_lines; x++) {
		for (y = 0; y < pad_cols; y++) {
			mvwaddch(pad_ptr, x, y, disp_char);
			if (disp_char == 'z')
				disp_char = 'a';
			else
				disp_char++;
		}
	}

	prefresh(pad_ptr, 5, 7, 2, 2, 9, 9);
	sleep(1);
	prefresh(pad_ptr, LINES + 5, COLS + 7, 5, 5, 21, 19);
	sleep(1);

	delwin(pad_ptr);
	endwin();

	return 0;
}
