#include <iostream>

using namespace std;

int main(void)
{
	size_t nCount(0U);
	char cKey('\0');

	cout << "※這支程式會計算使用者所輸入的字元數，\"#\"字號離開!! " << endl;
	
	do
	{
		cout << "Input: ";
		cin >> cKey;
		nCount++;
	}while(cKey!='#');
	cout << "您剛剛共輸入了 " << nCount-1 << " 個字元!!" << endl;

	return 0;
}
