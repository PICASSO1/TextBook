#include <stdio.h>
#include <string.h>

void Change(char *STR);

int main(void)
{
    char strTemp[81];

	memset(strTemp, 0, sizeof(strTemp));

	puts("請隨便輸入一個字串: ");
	gets(strTemp);
	Change(strTemp);
	puts("將剛剛的字串反向輸出: ");
	fputs(strTemp, stdout);
	putchar('\n');

	return 0;
}
//===========================================================
void Change(char *STR)
{
	size_t a, b, nLen=0;
    char strTemp[81];

	memset(strTemp, 0, sizeof(strTemp));

	strcpy(strTemp, STR);
	nLen=strlen(STR);
	for(a=0, b=nLen-1; (a<nLen)&&(b>=0); a++, b--)
		STR[a]=strTemp[b];
	STR[nLen]='\0';

	return;
}
