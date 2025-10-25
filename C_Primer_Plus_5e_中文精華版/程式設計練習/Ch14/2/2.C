#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Month
{
	char strFullName[10];       // 月份的全名
	char strBriefName[4];       // 月份的簡寫
	size_t nDays;               // 該月份的天數
	size_t nShow;               // 該月份的阿拉伯數字
};

int main(void)
{
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
	int n, nRet=0, m=-1;
	size_t nTemp=0;
	char strRet[5], strTemp[10];

	memset(strRet, 0, sizeof(strRet));
	memset(strTemp, 0, sizeof(strTemp));

	puts("這是一個利用結構來儲存月份資料的程式(Q/q to exit)!! ");
	puts("請選擇要查尋的方式: ");
	puts("1. 輸入月份全名 2. 輸入月份縮寫 3. 輸入月份的阿拉伯數字 ");
	while(scanf("%s", &strRet)==1)
	{
		if((strRet[0]=='Q') || (strRet[0]=='q'))
			break;
		nRet=atoi(strRet);
		if(nRet==1)
		{
			puts("請輸入月份全名(Q/q to exit): ");
			while(scanf("%s", &strTemp)==1)
			{
				if((strTemp[0]=='Q') || (strTemp[0]=='q'))
					break;
				for(n=0; n<12; n++)
				{
				    m=strcmp(strTemp, stMonth[n].strFullName);
					if(m==0)
						break;
				}
				if(m!=0)
					puts("輸入錯誤!! 請重新輸入!! ");
				else
		            printf("總天數: %d \n\n", stMonth[n].nDays);
				puts("請輸入月份全名(Q/q to exit): ");
			}
		}
		else if(nRet==2)
		{
			puts("請輸入月份縮寫(Q/q to exit): ");
			while(scanf("%s", &strTemp)==1)
			{
				if((strTemp[0]=='Q') || (strTemp[0]=='q'))
					break;
				for(n=0; n<12; n++)
				{
				    m=strcmp(strTemp, stMonth[n].strBriefName);
					if(m==0)
						break;
				}
				if(m!=0)
					puts("輸入錯誤!! 請重新輸入!! ");
				else
		            printf("總天數: %d \n\n", stMonth[n].nDays);
				puts("請輸入月份縮寫(Q/q to exit): ");
			}
		}
		else if(nRet==3)
		{
			puts("請輸入月份的阿拉伯數字(Q/q to exit): ");
			while(scanf("%s", &strTemp)==1)
			{
				if((strTemp[0]=='Q') || (strTemp[0]=='q'))
					break;
				nTemp=atoi(strTemp);
				if((nTemp<1) || (nTemp>12))
				{
				    puts("輸入錯誤!! 請重新輸入!! ");
					puts("請輸入月份的阿拉伯數字(Q/q to exit): ");
					continue;
				}
				for(n=0; n<12; n++)
				{
					if(nTemp==stMonth[n].nShow)
						break;
				}
	            printf("總天數: %d \n\n", stMonth[n].nDays);
				puts("請輸入月份的阿拉伯數字(Q/q to exit): ");
			}
		}
		else // if(nRet<0 || nRet>3)
			puts("輸入錯誤!! 請重新輸入!! ");
	    puts("請選擇要查尋的方式: ");
	    puts("1. 輸入月份全名 2. 輸入月份縮寫 3. 輸入月份的阿拉伯數字 ");
	}
    puts("結束程式!! Bye!! Bye!! ");

	return 0;
}
