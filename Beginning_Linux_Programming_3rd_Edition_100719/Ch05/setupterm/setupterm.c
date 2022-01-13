#include <stdio.h>
#include <term.h>
#include <ncurses.h>
#include <stdlib.h>

int 
main()
{
	setupterm("unlisted", fileno(stdout), (int *)NULL);
	fprintf(stdout, "Done!! \n");

	return 0;
}
