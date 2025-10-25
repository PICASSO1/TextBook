#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Show(char *STR);

int main(void)
{
	char strTemp[81];

	memset(strTemp, 0, sizeof(strTemp));

	puts("這支程式會把所輸入的字串，\"空白\"部份去除!! ");
	puts("請隨便輸入一個字串: ");
	while(fgets(strTemp, 81, stdin)!=NULL && strTemp[0]!='\n')
	{
	    Show(strTemp);
		putchar('\n');
		puts("請隨便輸入一個字串: ");
	}

    return 0;
}
//===================================================================
void Show(char *STR)
{
    size_t a, nLen=0;

	nLen=strlen(STR);
	for(a=0; a<nLen; a++)
	{
	    if(!isspace(STR[a]))
			putc(STR[a], stdout);
	}
	putchar('\n');

	return;
}
