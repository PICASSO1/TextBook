#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CSIZE 4

int Check(char *STR);

struct name
{
	char strTitle[21];
	char strLastName[21];
};
struct student
{
	struct name stName;
	double dGrade[3];
	double dAvg;
};

int main(void)
{
	struct student stStudent[CSIZE];
	int x, y, a, b=0, nCheck=0;
	double dTotal, dSum=0.000000, dResult=0.000000;
	char strTemp[10];

	memset(stStudent, 0, sizeof(stStudent));
	memset(strTemp, 0, sizeof(strTemp));

	puts("請輸入科目名稱: ");
	scanf("%s", &stStudent[0].stName.strTitle);
	for(a=1; a<CSIZE; a++)
		strcpy(stStudent[a].stName.strTitle, stStudent[0].stName.strTitle);
	puts("請輸入學生名字: ");
	while((scanf("%s", stStudent[b].stName.strLastName)==1))
	{
		a=0;
		while(a<3)
		{
			printf("請輸入第%d次分數: ", a+1); 
			scanf("%s", &strTemp);
			nCheck=Check(strTemp);
			if(nCheck==0)
			{
				puts("輸入錯誤!! 請重新輸入!!");
				continue;
			}
			stStudent[b].dGrade[a]=atof(strTemp);
			a++;
		}
		if((++b)>(CSIZE-1))      // 學生數
			break;
		puts("請輸入學生名字: ");
	}
	for(x=0; x<b; x++)
	{
		dTotal=0.000000;
		for(y=0; y<3; y++)      // 計算每個學生的平均分數
			dTotal+=stStudent[x].dGrade[y];
		stStudent[x].dAvg=dTotal/3;
		dSum+=stStudent[x].dAvg;
	}
	dResult=dSum/b;
	puts("您剛剛所輸入的資料如下: ");
	puts("Object  Student    1st    2nd    3rd     Average");
	for(x=0; x<b; x++)
	{
		printf("%s ", stStudent[x].stName.strTitle);
		printf("%-10s", stStudent[x].stName.strLastName);
		for(y=0; y<3; y++)
			printf(" %5.2lf ", stStudent[x].dGrade[y]);
		printf("  %5.2lf \n", stStudent[x].dAvg);
	}
	printf("總平均: %5.2lf \n", dResult);

	return 0;
}
//===========================================================================================
int Check(char *STR)
{
	size_t a, nLen=0;

	nLen=strlen(STR);
	for(a=0; a<nLen; a++)
	{
		if(!isdigit(STR[a]) && STR[a]!='.')
			return 0;
	}

	return 1;
}
