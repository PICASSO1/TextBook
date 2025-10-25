#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	size_t nMax(100U), nMin(1U), nAvg(0U), nAns(0U), nFlag(0U);
	char cKey('\0');

	cout << "※這是一個簡單的猜數字遊戲!! " << endl;
	cout << "請在心中想一個1~100的整數!!" << endl;
	while(1)
	{
		if(nMin==99 && nMax==100)
		{
			nMin = 100;
			nMax = 100;
		}
		nAvg = (nMax + nMin) / 2;
		while(1)
		{
			cout << "你想的數字是 " << nAvg << " 嗎(Y/N): ";
			cin >> cKey;
			if(toupper(cKey)=='Y')
			{
				nAns = nAvg;
				nFlag = 1;
				break;
			}
			else if(toupper(cKey)=='N')
			{
				if(nAvg==100)
				{
					cout << "真的不是100嗎?? " << endl;
					continue;
				}
				if(nAvg==1)
				{
					cout << "真的不是1嗎?? " << endl;
					continue;
				}
				nFlag = 0;
				break;
			}
			else
				;
		}
		while(nFlag==0)
		{
			cout << "你的數字大於 " << nAvg << " 嗎(Y/N): ";
			cin >> cKey;
			cout << endl;
			if(toupper(cKey)=='Y' || toupper(cKey)=='N')
				break;
		}
		if(nFlag==1)
			break;
		if(toupper(cKey)=='Y')
			nMin = nAvg;
		else // if(toupper(cKey)=='N')
			nMax = nAvg;
	}
	cout << "您心中所想的數字是: " << (nMin + nMax) / 2 << "!!" << endl;

	return 0;
}
