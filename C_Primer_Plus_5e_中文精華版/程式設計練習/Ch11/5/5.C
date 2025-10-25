#include <stdio.h>
#include <string.h>

int is_within(char *, char);

int main(void)
{
	int nRet=0;
	char strTemp[81];
	char cKey='\n';

	memset(strTemp, 0, sizeof(strTemp));

	puts("請隨便輸入一個字串: ");
	fgets(strTemp, 81, stdin);
	puts("請輸入要找的字元: ");
	cKey=getchar();
	nRet=is_within(strTemp, cKey);
	if(nRet==0)
		puts("沒找到唷!!");
	else // if(nRet==1)
		puts("找到嚕!!");

    return 0;
}
//=====================================================================
int is_within(char *STR, char C)
{
    size_t a, nLen=0;

	nLen=strlen(STR);
	for(a=0; a<nLen; a++)
	{
	    if(STR[a]==C)
			return 1;      // 回傳1表示有找到!!
	}
	return 0;      // 回傳0表示沒找到!!
}
