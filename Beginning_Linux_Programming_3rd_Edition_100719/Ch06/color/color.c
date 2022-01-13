#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/*
*	File Name: color.c
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
	int i = -1;

	initscr();
	if (!has_colors()) {
		endwin();
		perror("has_colors");
		fprintf(stderr, "Error - No color support on this terminal!! \n");
		exit(EXIT_FAILURE);
	}

	if (start_color() != OK){
		endwin();
		perror("start_color");
		fprintf(stderr, "Error - Could not initialize colors!! \n");
		exit(EXIT_FAILURE);
	}

	clear();
	mvprintw(5, 5, "There are %d COLORs, and %d COLOR_PAIRS available", COLORS, COLOR_PAIRS);
	refresh();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_GREEN);
	init_pair(3, COLOR_GREEN, COLOR_RED);
	init_pair(4, COLOR_YELLOW, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(7, COLOR_CYAN, COLOR_WHITE);
	for (i = 1; i <= 7; i++) {
		attroff(A_BOLD);
		attrset(COLOR_PAIR(i));
		mvprintw(5 + i, 5, "Color pair %d", i);
		attrset(COLOR_PAIR(i) | A_BOLD);
		mvprintw(5 + i, 25, "Bold color pair %d", i);
		refresh();
		sleep(1);
	}
	endwin();

	return 0;
}
