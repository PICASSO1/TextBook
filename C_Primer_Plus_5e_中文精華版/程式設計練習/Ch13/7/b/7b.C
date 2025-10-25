#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 81

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp1=NULL, *fp2=NULL, *fp3=NULL;
	int nFlag1=0, nFlag2=0, nFlag3=0;
	size_t nLen=0;
	char strTemp[243], strTemp1[MAX], strTemp2[MAX], strTemp3[MAX];
	char strTmp1[MAX], strTmp2[MAX], strTmp3[MAX];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strTemp1, 0, sizeof(strTemp1));
	memset(strTemp2, 0, sizeof(strTemp2));
	memset(strTemp3, 0, sizeof(strTemp3));
	memset(strTmp1, 0, sizeof(strTmp1));
	memset(strTmp2, 0, sizeof(strTmp2));
	memset(strTmp3, 0, sizeof(strTmp3));

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
		    while((fgets(strTmp1, MAX, fp1))!=NULL)
			{
				nLen=strlen(strTmp1);
				strncpy(strTemp1, strTmp1, nLen-2);
			    nFlag1=0;
			    break;
			}
		}
		if(nFlag2==0)
		{
		    nFlag2=1;
		    while((fgets(strTmp2, MAX, fp2))!=NULL)
			{
				nLen=strlen(strTmp2);
				strncpy(strTemp2, strTmp2, nLen-2);
			    nFlag2=0;
			    break;
			}
		}
		if(nFlag3==0)
		{
		    nFlag3=1;
		    while((fgets(strTmp3, MAX, fp3))!=NULL)
			{
				nLen=strlen(strTmp3);
				strncpy(strTemp3, strTmp3, nLen-2);
			    nFlag3=0;
			    break;
			}
		}
		if((nFlag1==1) && (nFlag2==1) && (nFlag3==1))
			break;
		else if((nFlag1==1) && (nFlag2==0) && (nFlag3==0))
		{
			sprintf(strTemp, "%s%s", strTemp2, strTemp3);
			puts(strTemp);
		}
		else if((nFlag1==0) && (nFlag2==1) && (nFlag3==0))
		{
			sprintf(strTemp, "%s%s", strTemp1, strTemp3);
			puts(strTemp);
		}
		else if((nFlag1==0) && (nFlag2==0) && (nFlag3==1))
		{
			sprintf(strTemp, "%s%s", strTemp1, strTemp2);
			puts(strTemp);
		}
		else if((nFlag1==0) && (nFlag2==1) && (nFlag3==1))
			puts(strTemp1);
		else if((nFlag1==1) && (nFlag2==0) && (nFlag3==1))
			puts(strTemp2);
		else if((nFlag1==1) && (nFlag2==1) && (nFlag3==0))
			puts(strTemp3);
		else // if((nFlag1==0) && (nFlag2==0) && (nFlag3==0))
		{
			sprintf(strTemp, "%s%s%s", strTemp1, strTemp2, strTemp3);
			puts(strTemp);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}
