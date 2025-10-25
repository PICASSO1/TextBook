#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 81

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp1=NULL, *fp2=NULL, *fp3=NULL;
	int nFlag1=0, nFlag2=0, nFlag3=0;
	char strTemp1[MAX], strTemp2[MAX], strTemp3[MAX];

	memset(strTemp1, 0, sizeof(strTemp1));
	memset(strTemp2, 0, sizeof(strTemp2));
	memset(strTemp3, 0, sizeof(strTemp3));

	if(argc==1)
	{
	    puts("請輸入檔名!! ");
		exit(0);
	}
	fp1=fopen(argv[1], "rb");
	if(fp1==NULL)
	{
	    puts("開啟第一個檔案失敗!! ");
		exit(1);
	}
	fp2=fopen(argv[2], "rb");
	if(fp2==NULL)
	{
	    puts("開啟第二個檔案失敗!! ");
		exit(1);
	}
	fp3=fopen(argv[3], "rb");
	if(fp3==NULL)
	{
	    puts("開啟第三個檔案失敗!! ");
		exit(1);
	}
	while(1)
	{
		if(nFlag1==0)
		{
		    nFlag1=1;
		    while((fgets(strTemp1, MAX, fp1))!=NULL)
			{
		        fputs(strTemp1, stdout);
			    nFlag1=0;
			    break;
			}
		}
		if(nFlag2==0)
		{
		    nFlag2=1;
		    while((fgets(strTemp2, MAX, fp2))!=NULL)
			{
		        fputs(strTemp2, stdout);
			    nFlag2=0;
			    break;
			}
		}
		if(nFlag3==0)
		{
		    nFlag3=1;
		    while((fgets(strTemp3, MAX, fp3))!=NULL)
			{
		        fputs(strTemp3, stdout);
			    nFlag3=0;
			    break;
			}
		}
		if((nFlag1==1) && (nFlag2==1) && (nFlag3==1))
			break;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}
