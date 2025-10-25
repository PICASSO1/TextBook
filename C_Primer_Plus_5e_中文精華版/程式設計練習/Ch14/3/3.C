#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXTUTL 40
#define MAXBKS 100

struct book
{
	char strOrder[MAXTITL];      // 訂單
	char title[MAXTUTL];         // 書名
	float value;                 // 價格
};

int main(void)
{
	struct book libry[MAXBKS];
	int index, count=0;

	memset(libry, 0, sizeof(libry));

//	printf("Please enter the book title: \n");
	puts("請輸入訂單: ");
//	printf("press [enter] at the start of a line to stop. \n");
	puts("在一行的開始按[Enter]可以離開!! ");
	while(count<MAXBKS && gets(libry[count].strOrder)!=NULL && libry[count].strOrder[0]!='\0')
	{
		printf("現在請輸入書名: \n");
		gets(libry[count].title);
		
		printf("現在請輸入價格: \n");
		scanf("%f",&libry[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
//			printf("Enter the next strOrder. \n");
            puts("請輸入下一筆訂單: ");
	}
	printf("這裡是您剛才所輸入的訂單列表: \n");
	for(index=0;index<count;index++)
		printf("訂單編號: %s, 書名: %s, 價格: $%.2f \n", libry[index].strOrder, libry[index].title, libry[index].value);

	return 0;
}
