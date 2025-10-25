#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	int nNum(0), nTotal(0);
	char cKey('\0');

	cout << "※這支程式會計算使用者所輸入數字的總合!! " << endl;

	do
	{
		cout << "請輸入一個整數: ";
		cin >> nNum;
		nTotal += nNum;
		do
		{
			cout << "你要再輸入整數嗎?? ";
			cin >> cKey;
		}while(toupper(cKey)!='Y' && toupper(cKey)!='N');
	}while(toupper(cKey)=='Y');
	cout << "總和是: " << nTotal << "!! " << endl;

	return 0;
}
