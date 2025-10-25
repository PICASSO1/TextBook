#include <stdio.h>
#include <string.h>

int main(void)
{
    char strLine[20];
	memset(strLine, 0, sizeof(strLine));

	while(fgets(strLine, 20, stdin)!=NULL && strLine[0]!='\n')
		fputs(strLine, stdout);
	return 0;
}