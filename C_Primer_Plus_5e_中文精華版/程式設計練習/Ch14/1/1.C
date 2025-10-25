#include <stdio.h>
#include <string.h>

int main(void)
{
	struct Month
	{
		char strFullName[10];       // 月份的全名
		char strBriefName[4];       // 月份的簡寫
		size_t nDays;               // 該月份的天數
		size_t nShow;               // 該月份的阿拉伯數字
	};

	struct Month stMonth[12] =
	{
		{"January", "Jan", 31, 1 },
		{"February", "Feb", 28, 2 },
		{"March", "Mar", 31, 3 },
		{"April", "Apr", 30, 4 },
		{"May", "May", 31, 5 },
		{"June", "Jun", 30, 6 },
		{"July", "Jul", 31, 7 },
		{"Auguest", "Aug", 31, 8 },
		{"September", "Sep", 30, 9 },
		{"October", "Oct", 31, 10 },
		{"November", "Nov", 30, 11 },
		{"December", "Dec", 31, 12 }
	};
	int n, nRet=0;
	char strMonthName[10];

	memset(strMonthName, 0, sizeof(strMonthName));

	puts("這是一個利用結構來儲存月份資料的程式!! ");
	fputs("請輸入要顯示的月份的英文全名(Q/q to exit): ", stdout);
	while(scanf("%s", strMonthName)==1)
	{
		if(strMonthName[0]=='Q' || strMonthName[0]=='q')
			break;
		for(n=0; n<12; n++)
		{
			nRet=strcmp(strMonthName, stMonth[n].strFullName);
		    if(nRet==0)
				break;
		}
		printf("月份: %s \n", stMonth[n].strFullName);
		printf("簡寫: %s \n", stMonth[n].strBriefName);
		printf("天數: %d \n", stMonth[n].nDays);
		printf("數字: %d \n", stMonth[n].nShow);
		fputs("請輸入要顯示的月份的英文全名(Q/q to exit): ", stdout);
	}
	puts("Bye!! Bye!! ");

	return 0;
}
