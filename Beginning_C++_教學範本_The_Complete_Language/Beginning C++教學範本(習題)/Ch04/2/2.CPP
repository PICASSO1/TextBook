#include <iostream>

using namespace std;

int main(void)
{
	unsigned int nNum(0U);

	cout << "請輸入一個介於1~100的整數: ";
	cin >> nNum;

	if(nNum<1 || nNum>100)
		cout << "輸入錯誤!!" << endl;
	else
	{
		if(nNum<50)
			cout << "此數小於50." << endl;
		else if(nNum>50)
			cout << "此數大於50." << endl;
		else // if(nNum==50)
			cout << "此數等於50." << endl;
	}
	cout << "程式結束!!" << endl;

	return 0;
}
