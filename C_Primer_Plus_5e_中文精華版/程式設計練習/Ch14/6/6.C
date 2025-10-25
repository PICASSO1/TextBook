#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PEOPLE 9            // 幾個人

struct st
{
	int nBackNum;               // 背號
	char strFirstName[20];      // 名字
	char strLastName[20];       // 姓氏
	int nOrder;                 // 棒次
	int nHitTime;               // 打擊次數
	int nSafe;                  // 保送
	int nRBIS;                  // 打點
	double dHitRate;            // 打擊率: 保送/打擊次數
};

void Process(char *Data, struct st stData[], int n);

int main(int argc, char *argv[], char *envp[])
{
	struct st stData[PEOPLE*2];
	FILE *fp=NULL;
	int a;
	char strTemp[30];

	memset(stData, 0, sizeof(stData));
	memset(strTemp, 0, sizeof(strTemp));

	if(argc < 2)
	{
		puts("請輸入檔名: ");
		exit(1);
	}
	fp=fopen(argv[1], "rb");
	if(fp==NULL)
	{
		printf("開啟%s失敗!! \n\a", argv[1]);
		fclose(fp);
		exit(1);
	}
	else
	{
		while(fgets(strTemp, 30, fp)!=NULL)
		{
			Process(strTemp, stData, a);
			a++;
		}
		fclose(fp);
	}
	puts("從檔案中的記錄及打擊率計算如下: ");
	puts("NO FirstName LastName 棒次 次數 保送 打點 打擊率");
	for(a=0; a<PEOPLE; a++)
	{
		stData[a].dHitRate=(double)(stData[a].nSafe)/(double)(stData[a].nHitTime);
		printf("%02d ", stData[a].nBackNum);
		printf("%-9s ", stData[a].strFirstName);
		printf("%-10s ", stData[a].strLastName);
		printf("%-3d ", stData[a].nOrder);
		printf("%-4d ", stData[a].nHitTime);
		printf("%-4d ", stData[a].nSafe);
		printf("%-4d ", stData[a].nRBIS);
		printf("%.2lf \n", stData[a].dHitRate);
	}

	return 0;
}
//=========================================================================
void Process(char *Data, struct st stData[], int n)
{
	int a, nIndex=1, nFlag=0;
	char *ptr=NULL;

	ptr=strtok(Data, " ");
	for(a=0; a<n; a++)
	{
		if(stData[a].nBackNum==atoi(ptr))      // 表示有重覆!!
		{
			nFlag=1;
			break;
		}
	}

	if(nFlag==0)      // 沒重覆，將資料新增到結構中
	{
		stData[n].nBackNum=atoi(ptr);
		while(ptr=strtok(NULL, " "))
		{
			if(nIndex==1)
				strcpy(stData[n].strFirstName, ptr);
			else if(nIndex==2)
				strcpy(stData[n].strLastName, ptr);
			else if(nIndex==3)
				stData[n].nOrder=atoi(ptr);
			else if(nIndex==4)
				stData[n].nHitTime=atoi(ptr);
			else if(nIndex==5)
				stData[n].nSafe=atoi(ptr);
			else //if(nIndex==6)
				stData[n].nRBIS=atoi(ptr);
			nIndex++;
		}
	}
	else // if(nFlag==1)      // 有重覆，將原本結構中的舊資料帶出來，加上新的資料
	{
		while(ptr=strtok(NULL, " "))
		{
			if(nIndex==1)
				;
			else if(nIndex==2)
				;
			else if(nIndex==3)
				stData[a].nOrder+=atoi(ptr);
			else if(nIndex==4)
				stData[a].nHitTime+=atoi(ptr);
			else if(nIndex==5)
				stData[a].nSafe+=atoi(ptr);
			else //if(nIndex==6)
				stData[a].nRBIS+=atoi(ptr);
			nIndex++;
		}
	}

	return;
}
