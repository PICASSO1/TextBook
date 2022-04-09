#include <stdio.h>

#include "./Child/func1.h"

int 
main(argc, argv, envp)
int argc; 
char *argv[]; 
char **envp; 
{
	int ggg = 0;

	printf("%s (%d): %s \n", __FUNCTION__, __LINE__, CCCCC);
	myFunC1(&ggg);
	printf("ggg = %d \n", ggg);

	return 0;
}
