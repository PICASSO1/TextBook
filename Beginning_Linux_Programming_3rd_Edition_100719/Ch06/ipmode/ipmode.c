#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/*
*	File Name: ipmode.c
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

#define	PW_LEN		25
#define	NAME_LEN	256

int 
main()
{
	char name[NAME_LEN];
	char password[PW_LEN];
	char *real_password = "xyzzy";
	int i = 0;

	initscr();
	move(5, 10);
	printw("%s", "Please login: ");

	move(7, 10);
	printw("%s", "User Name: ");
	memset(name, '\0', sizeof(char) * NAME_LEN);
	getstr(name);

	move(9, 10);
	printw("%s", "Password: ");
	refresh();

	cbreak();
	noecho();
	memset(password, '\0', sizeof(char) * PW_LEN);
	while (i < PW_LEN) {
		password[i] = getch();
		move(9, 20 + i);
		addch('*');
		refresh();
		if (password[i] == '\n')
			break;
		if (strcmp(password, real_password) == 0)
			break;
		i++;
	}

	echo();
	nocbreak();
	move(11, 10);
	if (strcmp(password, real_password) == 0)
		printw("%s", "Correct!! ");
	else
		printw("%s", "Wrong!! ");
	refresh();
	sleep(5);	// Add this line....

	endwin();

	return 0;
}
