#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp=NULL;
	long lnRet=0L;
	char cKey='\0';
	char strTemp[16], strFileName[16];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strFileName, 0, sizeof(strFileName));

	puts("請輸入檔名: ");
	scanf("%s", &strTemp);
	strcpy(strFileName, "./");
	strcat(strFileName, strTemp);
	fp=fopen(strFileName, "rb");
	if(fp==NULL)
	{
	    puts("開檔失敗!! ");
		fclose(fp);
		exit(1);
	}
	else
	{
	    puts("請輸入要從那裡開始讀取: ");
		while(scanf("%ld", &lnRet)==1)
		{
		    fseek(fp, lnRet, SEEK_SET);
			cKey=getc(fp);
			while(cKey!=EOF)
			{
				putchar(cKey);
				if(cKey=='\n')
					break;
				cKey=getc(fp);
			}
			putchar('\n');
			puts("請輸入要從那裡開始讀取: ");
		}
		fclose(fp);
	}

	return 0;
}
