#include <stdio.h>
#include <stdlib.h>

int 
main()
{
	char *ptr = (char *)calloc(sizeof(char), 1024);
	char ch;

	/* Uninitialized read */
	ch = ptr[1024];
	/* Write beyond the block */
	ptr[1024] = '\0';
	/* Orphan the block */
	ptr = NULL;

	return 0;
}
