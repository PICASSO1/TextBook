#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 12
#define NAMESIZE 20
#define TEXT "./Text.TXT"
typedef struct
{
	int nSeatID;
	char cSeat;
	char strFirstName[NAMESIZE];
	char strLastName[NAMESIZE];
}_ST;

int Show(void);
void PreInit(_ST stSEAT[]);      // 從檔案中載入資料來初始化結構
void FuncA(_ST stSEAT[]);      // 秀出空座位的號碼
void FuncB(_ST stSEAT[]);      // 秀出座位的名單
void FuncC(_ST stSEAT[]);      // 依字母順序秀出座位名單
void FuncD(_ST stSEAT[]);      // 分配一個客戶到一個座位
void FuncE(_ST stSEAT[]);      // 刪除一個已分配的座位
void FuncF(_ST stSEAT[]);      // 離開程式要存檔

int main(void)
{
	_ST stSeat[SIZE];
	int nRet=0; 

	memset(stSeat, 0, sizeof(stSeat));

	PreInit(stSeat);
	nRet=Show();
	while(nRet!=6)
	{
		if(nRet==1)
			FuncA(stSeat);
		else if(nRet==2)
			FuncB(stSeat);
		else if(nRet==3)
			FuncC(stSeat);
		else if(nRet==4)
			FuncD(stSeat);
		else // if(nRet==5)
			FuncE(stSeat);
		nRet=Show();
	}
	FuncF(stSeat);
	puts("Exit Programm!! ");

	return 0;
}
//==============================================================================
int Show(void)
{
	int nRet=0;
	char cKey='\0';

	puts("To choose a function, enter its letter label: ");      // 選擇一個功能，輸入它的字母標籤
	puts("a) Show number of empty seats ");      // 秀出空座位的號碼
	puts("b) Show list of seats ");      // 秀出座位的名單
	puts("c) Show alphabetical list of seats ");      // 依字母順序秀出座位名單
	puts("d) Assign a customer to a seat assignment ");      // 分配一個客戶到一個座位
	puts("e) Delete a seat assignment ");      // 刪除一個座位分配
	puts("f) Quit ");

	while(1)
	{
		scanf("%c", &cKey);
		cKey=toupper(cKey);
		if((cKey<'A') || (cKey>'F'))
			continue;
		else
		{
			switch(cKey)
			{
			    case 'A': nRet=1;
					      break;
			    case 'B': nRet=2;
					      break;
			    case 'C': nRet=3;
					      break;
			    case 'D': nRet=4;
					      break;
			    case 'E': nRet=5;
					      break;
			    case 'F': nRet=6;
					      break;
			}
			break;
		}
	} // while end

	return nRet;
}
//==============================================================================
void FuncA(_ST stSEAT[])      // 秀出空座位的號碼
{
	int a;

	for(a=0; a<SIZE; a++)      // 先檢查是否還有空座位
	{
		if(stSEAT[a].cSeat=='N')
			break;
	}
	if(a==SIZE)
		puts("Sorry!! No any seat!! ");
	else
	{
        fputs("The number of empty seats: ", stdout);
        for(a=0; a<SIZE; a++)
        {
			if(stSEAT[a].cSeat=='N')
				printf("%2d ", stSEAT[a].nSeatID);
        }
	}
	puts("\n");

	return;
}
//==============================================================================
void FuncB(_ST stSEAT[])      // 秀出座位的名單
{
	int a, b=0;
	for(a=0; a<SIZE; a++)
	{
		if(stSEAT[a].cSeat=='Y')
		{
			b=1;
			printf("%s %s %d \n", stSEAT[a].strFirstName, stSEAT[a].strLastName, stSEAT[a].nSeatID);
		}
	}
	if(b==0)
		puts("No any customer!! ");
	putchar('\n');

	return;
}
//==============================================================================
void FuncC(_ST stSEAT[])      // 依字母順序秀出座位名單
{
	_ST stTemp[SIZE], Temp;
	int a, b=0, c=0, x=0;
	double dTime=0.000000;

	memset(stTemp, 0, sizeof(stTemp));
	memset(&Temp, 0, sizeof(Temp));

	for(a=0 ; a<SIZE; a++)      // 把原本的結構內容，cSeat='Y'的覆製到暫存的結構
	{
		if(stSEAT[a].cSeat=='Y')
		{
			stTemp[c]=stSEAT[a];
			c++;
		}      // c代表有幾筆資料
	}
	dTime=pow((c-1), 2.000000);
	// 若有5筆資料，則須排序(5-1)^2 = 4^2 = 16 (次)
 	for(a=0; a<dTime; a++)      // 開始排序
	{
		if(stTemp[x].strFirstName[0] > stTemp[x+1].strFirstName[0])
		{
			Temp=stTemp[x+1];
			stTemp[x+1]=stTemp[x];
			stTemp[x]=Temp;
		}
		if(x==(c-2))
			x=0;
		else
			x++;
	}
	for(a=0; a<SIZE; a++)      // 秀出排序過後的資料
	{
		if(stTemp[a].cSeat=='Y')
		{
			b=1;
			printf("%s %s %d \n", stTemp[a].strFirstName, stTemp[a].strLastName, stTemp[a].nSeatID);
		}
	}
	if(b==0)
		puts("No data to sort!! ");
	putchar('\n');

	return;
}
//==============================================================================
void FuncD(_ST stSEAT[])      // 分配一個客戶到一個座位
{
	int a, nID=0;
	char strFirstName[NAMESIZE], strLastName[NAMESIZE], strID[3];

	memset(strFirstName, 0, sizeof(strFirstName));
	memset(strLastName, 0, sizeof(strLastName));
	memset(strID, 0, sizeof(strID));

	for(a=0; a<SIZE; a++)      // 先檢查機位是否已訂滿
	{
		if(stSEAT[a].cSeat=='N')
			break;
	}
	if(a==SIZE)
	{
		puts("The seats are all ordered!! ");
		putchar('\a');
	}
	else
	{
		fputs("Please enter customer's First Name: ", stdout);
		scanf("%s", &strFirstName);
		fputs("Please enter customer's Last Name: ", stdout);
		scanf("%s", &strLastName);
		fputs("Please enter the seat ID: ", stdout);
		while(scanf("%s", &strID)==1)
		{
			nID=atoi(strID);
			if(nID==0)
			{
				fputs("Please enter the seat ID: ", stdout);
				continue;
			}
			else if((nID<0) || (nID>12))
			{
				fputs("Please enter the seat ID: ", stdout);
				continue;
			}
			else
			{
				if(stSEAT[nID-1].cSeat=='Y')
				{
					puts("This seat is aready order!! ");
					fputs("Please enter the seat ID: ", stdout);
					continue;
				}
				else
					break;
			}
		}
		strcpy(stSEAT[nID-1].strFirstName, strFirstName);
		strcpy(stSEAT[nID-1].strLastName, strLastName);
		stSEAT[nID-1].cSeat='Y';
	}
	putchar('\n');

	return;
}
//==============================================================================
void FuncE(_ST stSEAT[])      // 刪除一個已分配的座位
{
	int nID=0, nFlag=0;
	char strID[3];

	memset(strID, 0, sizeof(strID));

	fputs("Please enter a seat ID: ", stdout);
	// 因為姓氏和名字有可能會重覆，所以必須以座位號碼做索引
	while(scanf("%s", &strID)==1)
	{
		nID=atoi(strID);
		if(nID==0)
			break;
		else if((nID<0) || (nID>12))
		{
			fputs("Please enter a seat ID: ", stdout);
			continue;
		}
		else
		{
			if(stSEAT[nID-1].cSeat=='N')
			{
				nFlag=1;
				puts("This seat isn't ordered yet!! ");
			}
			break;
		}
	}
	if(nFlag==0)
	{
		strcpy(stSEAT[nID-1].strFirstName, "\0");
		strcpy(stSEAT[nID-1].strLastName, "\0");
		stSEAT[nID-1].cSeat='N';
		printf("The seat %d was already delete!! \n", nID);
	}
	putchar('\n');

	return;
}
//==============================================================================
void PreInit(_ST stSEAT[])      // 從檔案中載入資料來初始化結構
{
	FILE *fp=NULL;
	int a, nIndex, n=0;
	char *ptr=NULL;
	char strTemp[50];

	memset(strTemp, 0, sizeof(strTemp));

	for(a=0; a<SIZE; a++)      // 因為一開始，機位一定都沒人訂位，所以要把cSeat都設為'N'
	{
		stSEAT[a].nSeatID=(a+1);
		stSEAT[a].cSeat='N';
	}
	fp=fopen(TEXT, "a");
	fclose(fp);
	fp=fopen(TEXT, "rb");
	if(fp==NULL)
	{
		printf("ERROR!! \n\a");
		fclose(fp);
		exit(1);
	}
	else
	{
		while(fscanf(fp, "%s", &strTemp)==1)
		{
			nIndex=1;
			ptr=strtok(strTemp, ",");
			n=atoi(ptr)-1;
			stSEAT[n].cSeat='Y';
			while((ptr=strtok(NULL, ","))!=NULL)
			{
				if(nIndex==1)
					strcpy(stSEAT[n].strFirstName, ptr);
				else // if(nIndex==2)
					strcpy(stSEAT[n].strLastName, ptr);
				nIndex++;
			}
		}
		fclose(fp);
	}
	for(a=0; a<SIZE; a++)
	{
		if(stSEAT[a].cSeat!='Y')
			stSEAT[a].cSeat='N';
	}
	return;
}
//==============================================================================
void FuncF(_ST stSEAT[])      // 離開程式要存檔
{
	FILE *fp=NULL;
	int a;

	fp=fopen(TEXT, "wb");
	if(fp==NULL)
	{
		printf("ERROR!! \n\a");
		fclose(fp);
		exit(1);
	}
	else
	{
	    for(a=0; a<SIZE; a++)
	    {
		    if(stSEAT[a].cSeat=='Y')
			    fprintf(fp, "%02d,%s,%s\n", stSEAT[a].nSeatID, stSEAT[a].strFirstName, stSEAT[a].strLastName);
	    }
	    fclose(fp);
	}

	return;
}
