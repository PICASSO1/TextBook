#include <iostream>
#include <iomanip>
#include <cstring>
#include "AUTO.H"

using namespace std;

size_t Show(void)
{
	size_t nKey(0);

	while(1)
	{
		cout << "請選擇要轉換的幣制: " << endl;
		cout << "1. 台幣 -> 人民幣." << endl;
		cout << "2. 人民幣 -> 台幣. " << endl;
		cin >> nKey;
		if(nKey==1 || nKey==2)
			break;
		else
			exit(0);
	}

	return nKey;
}
//===========================================================================
void Change(size_t nRet)
{
	struct Rate rate;

	memset(&rate, 0, sizeof(&rate));

	if(nRet == 1)
	{
		while(1)
		{
			cout << "請輸入台幣: ";
			cin >> rate.Taiwan;
			if(rate.Taiwan < 0)
				break;
			rate.Chinese = rate.Taiwan / 4;
			cout << endl;
			cout << "台幣 " << rate.Taiwan << " 相當於人民幣 " << setprecision(2) << fixed << rate.Chinese << " 元!! \n" << endl;
		}
	}
	else // if(nRet == 2)
	{
		while(1)
		{
			cout << "請輸入人民幣: ";
			cin >> rate.Chinese;
			if(rate.Chinese < 0)
				break;
			rate.Taiwan = rate.Chinese * 4;
			cout << endl;
			cout << "人民幣 " << rate.Chinese << " 相當於台幣 " << setprecision(2) << fixed << rate.Taiwan << " 元!! \n" << endl;
		}
	}

	return;
}
