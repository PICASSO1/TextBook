#include <stdio.h>
#include <string.h>

int main(void)
{
	int a;
    char strTemp[81];

	memset(strTemp, 0, sizeof(strTemp));

	fputs("請隨便輸入一個字串: \n", stdout);
	fgets(strTemp, 81, stdin);
	for(a=0; a<81; a++)
	{
	    if(strTemp[a]==' ' || strTemp[a]==0x09 || strTemp[a]=='\n')
			break;
		else
			putc(strTemp[a], stdout);
	}

	putchar('\n');
	return 0;
}
