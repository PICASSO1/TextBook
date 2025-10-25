#include <iostream>

using namespace std;

int FunC(int Flag, size_t &NUM, size_t Month=0U);

int main(void)
{
	int nRet(0);
	size_t nYear(0U), nMonth(0U), nDay(0U);

	cout << "這支程式可以輸入您的生日並顯示之!! " << endl;
	while(1)
	{
		cout << "請輸入年: ";
		cin >> nYear;
		nRet = FunC(1, nYear);
		if(nRet==1)
		{
			nRet=0;
			break;
		}
		else
			cout << "輸入錯誤!! 請重新輸入!! " << endl;
	}
	while(1)
	{
		cout << "請輸入月: ";
		cin >> nMonth;
		nRet = FunC(2, nMonth);
		if(nRet==1)
		{
			nRet=0;
			break;
		}
		else
			cout << "輸入錯誤!! 請重新輸入!! " << endl;
	}
	while(1)
	{
		cout << "請輸入日: ";
		cin >> nDay;
		nRet = FunC(3, nDay, nMonth);
		if(nRet==1)
		{
			nRet=0;
			break;
		}
		else
			cout << "輸入錯誤!! 請重新輸入!! " << endl;
	}
	cout << "您剛剛所輸入的生日為: "
		 << nYear << "年 " << nMonth << "月 " << nDay << "日." << endl;

	return 0;
}
//=================================================================
int FunC(int Flag, size_t &NUM, size_t Month)
{
	int nRet(0);

	if(Flag==1)
	{
		if(NUM>=1907 && NUM<=2007)
			nRet=1;
	}
	if(Flag==2)
	{
		if(NUM>=1 && NUM<=12)
			nRet=1;
	}
	if(Flag==3)
	{
		if(Month==1 || Month==3 || Month==5 || Month==7 || Month==8 || Month==10 || Month==12)
		{
			if(NUM>=1 && NUM<=31)
				nRet=1;
		}
		else if(Month==4 || Month==6 || Month==9 || Month==11)
		{
			if(NUM>=1 && NUM<=30)
				nRet=1;
		}
		else // if(Month==2)
		{
			if(NUM>=1 && NUM<=29)
				nRet=1;
		}
	}

	return nRet;
}


