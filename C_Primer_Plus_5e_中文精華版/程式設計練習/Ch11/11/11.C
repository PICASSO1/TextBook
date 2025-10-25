#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	size_t a, nLen=0;
	int nUpper=0, nLower=0, nDigit=0, nPunct=0, nSpace=0;
	char cKey='\0';
    char strTemp[81];

	memset(strTemp, 0, sizeof(strTemp));

	puts("叫繦獽块︽: ");
	fgets(strTemp, 81, stdin);
	nLen=strlen(strTemp);
	for(a=0; a<nLen; a++)
	{
	    if(isupper(strTemp[a]))      // 糶ダ计
			nUpper++;
		else if(islower(strTemp[a]))      // 糶ダ计
			nLower++;
		else if(isdigit(strTemp[a]))      // 计计
			nDigit++;
		else if(isspace(strTemp[a]))      // フ计
			nSpace++;
		else if(ispunct(strTemp[a]))     // 夹翴才腹计
			nPunct++;
	}
	nLen-=(nSpace+nPunct+nDigit);
	printf("硂︽﹃ %d  \n", nLen);
	printf("ㄤいΤ %d 糶ダ \n", nUpper);
	printf("Τ %d 糶ダ \n", nLower);
	printf("Τ %d 夹翴才腹 \n", nPunct);
	printf("の %d 计!! \n", nDigit);

	return 0;
}
