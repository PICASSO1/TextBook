#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

/*
*	File Name: screen1.c
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
	initscr();
	move(5, 15);
	printw("%s", "Hello!! World!! \n");
	refresh();

	sleep(2);
	endwin();

	return 0;
}
