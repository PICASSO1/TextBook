#include <stdio.h>
#include <term.h>
#include <ncurses.h>
#include <stdlib.h>

int 
main()
{
	int nrows = 0, ncolumns = 0;

	setupterm(NULL, fileno(stdout), (int *)NULL);
	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	fprintf(stdout, "This terminal has %d columns and %d rows. \n", ncolumns, nrows);

	return 0;
}
