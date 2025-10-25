#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp=NULL;
	int a=0;
	char cKey='\n';
	char strTemp[81], strFileName[16];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strFileName, 0, sizeof(strFileName));

	if(argc!=3)
	{
	    puts("請依序輸入： 執行檔名稱、原始檔案、複製檔案!!");
		exit(1);
	}
	if(strcmp(argv[1], argv[2])==0)
	{
	    puts("來源檔及目的檔不可相同!!");
		exit(1);
	}
	strcmp(strFileName, "./");
	strcat(strFileName, argv[1]);
	fp=fopen(strFileName, "rb");      // 開啟原始檔!!
	if(fp==NULL)
	{
	    puts("開啟原始檔失敗!!");
		fclose(fp);
		exit(1);
	}
	else
	{
		cKey=getc(fp);
	    while(cKey!=EOF)
		{
			strTemp[a]=cKey;
			a++;
			cKey=getc(fp);
		}
		fclose(fp);
	}
	memset(strFileName, 0, sizeof(strFileName));
	strcmp(strFileName, "./");
	strcat(strFileName, argv[2]);
	fp=fopen(strFileName, "ab");    // 開啟目的檔案!!
	if(fp==NULL)
	{
	    puts("複製檔案失敗!! ");
		fclose(fp);
		exit(1);
	}
	else
	{
	    a=0;
		while(strTemp[a]!='\0')
		{
		    putc(strTemp[a], fp);
			a++;
		}
		fclose(fp);
		puts("YA!! 複製完成!! ");
	}

	return 0;
}
