#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AnotherFunC(char KEY, int Flag);

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp=NULL;
	int a, n=0, nRet=0;
	char cKey1='\0', cKey2='\0';

	nRet=argc;
	if(nRet==1)      // 只有輸入執行檔名，沒輸入要尋找的字元和檔案!!
		AnotherFunC(cKey1, 0);
	else if(nRet==2)      // 只有輸入執行檔名和要尋找的字元，沒輸入要尋找的檔案!!
	{
		cKey1=argv[1][0];
		AnotherFunC(cKey1, 1);
	}
	else      // if(nRet>2), 執行檔名、要尋找的字元和檔案都輸入完全!!
	{
	    cKey1=argv[1][0];
		for(a=2; a<nRet; a++)
		{
		    fp=fopen(argv[a], "rb");
			if(fp==NULL)
			{
			    printf("開啟%s失敗!! \n", argv[a]);
				fclose(fp);
				exit(1);
			}
			else
			{
				n=0;
				while((cKey2=getc(fp))!=EOF)
				{
				    if(cKey1==cKey2)
						n++;
				}
				fclose(fp);
				printf("在%s中，%c出現%d次!! \n", argv[a], cKey1, n);
			}
		}
	}

	return 0;
}
//==========================================================================
void AnotherFunC(char KEY, int Flag)
{
	FILE *fp=NULL;
	int n=0;
	char cKey1='\n', cKey2='\n';
	char strTemp[16], strFileName[16];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strFileName, 0, sizeof(strFileName));

	if(Flag==0)
	{
	    puts("請輸入要尋找的字元: ");
        cKey1=getchar();
	}
	else
		cKey1=KEY;

	puts("請輸入要尋找的檔案(Q/q to exit): ");
	while(scanf("%s", &strTemp)==1)
	{
		if((strTemp[0]=='Q') || (strTemp[0]=='q'))
			break;
	    strcpy(strFileName, "./");
	    strcat(strFileName, strTemp);
	    fp=fopen(strFileName, "rb");
	    if(fp==NULL)
	    {
	        puts("手動輸入開檔失敗!! ");
		    fclose(fp);
		    exit(1);
	    }
	    else
	    {
			n=0;
	        while((cKey2=getc(fp))!=EOF)
		    {
		        if(cKey2==cKey1)
				    n++;
		    }
		    fclose(fp);
		    printf("在%s中，%c出現%d次!! \n", strTemp, cKey1, n);
	    }
		puts("請輸入要尋找的檔案(Q/q to exit): ");
	}

	return;
}
