#include <stdio.h>
#include <stdlib.h>

int 
main()
{
	char *ptr = NULL;

	ptr = (char *)malloc(sizeof(char) * 1024);
	ptr[0] = '\0';

	// Now write beyond the block
	ptr[1024] = '\0';

	return 0;
}

/*
NOTE:
The index of 'ptr', only 0~1023; we couldn't access ptr[1024]!!
*/
