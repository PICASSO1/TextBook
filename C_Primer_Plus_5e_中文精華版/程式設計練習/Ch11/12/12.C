#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, nCount=0;

	nCount=argc-1;
	for(a=nCount; nCount>0; nCount--)
	    printf("%s ", argv[nCount]);
	putchar('\n');

    return 0;
}
