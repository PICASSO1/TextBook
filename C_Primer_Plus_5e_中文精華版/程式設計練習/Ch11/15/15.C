#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81

void Change(char *STR, int n);
void ErrMsg(void);

int main(int argc, char *argv[], char *envp[])
{
	int nRet=0;
	char strTemp[SIZE];

	memset(strTemp, 0, sizeof(strTemp));

	puts("請隨便輸入一個字串: ");
	fgets(strTemp, SIZE, stdin);
	if(strcmp("-p", argv[1])==0)
		nRet=-1;
	else if(strcmp("-u", argv[1])==0)
		nRet=1;
	else if(strcmp("-l", argv[1])==0)
		nRet=2;
	else
		nRet=0;
	while(1)
	{
	    switch(nRet)
	    {
	        case -1: Change(strTemp, nRet);
				     break;
		    case 1: Change(strTemp, nRet);
				    break;
		    case 2: Change(strTemp, nRet);
				    break;
		    default: ErrMsg();
				     break;
	    }
		break;      // break可以用在switch和迴圈；但continue只能用在迴圈!! 切記、切記!!
	}
	puts("程式結束!! ");

	return 0;
}
//============================================================================
void Change(char *STR, int n)
{
	size_t a, nLen=0;

	nLen=strlen(STR);
    if(n==-1)
	{
		for(a=0; a<nLen; a++)
	        putchar(STR[a]);
	}
	else if(n==1)
	{
		for(a=0; a<nLen; a++)
			putchar(toupper(STR[a]));
	}
	else // if(n==2)
	{
	    for(a=0; a<nLen; a++)
			putchar(tolower(STR[a]));
	}

	return;
}
//===============================================================================
void ErrMsg(void)
{
    puts("我去你媽的!! 我叫你輸入什麼，你給我輸入什麼?? 再來一遍!! ");

	return;
}
