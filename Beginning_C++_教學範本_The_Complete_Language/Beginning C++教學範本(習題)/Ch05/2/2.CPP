#include <iostream>

using namespace std;

int main(void)
{
	size_t nTimes(30U);
	int nNum(0);

	cout << "※這支程式會執行" << nTimes << "次，並秀出不能被3或5整除的數字!! " << endl;
	cout << "請輸入欲起始的數字: ";
	cin >> nNum;

	for(int i(0); i<nTimes; i++)
	{
		if(nNum%3!=0 && nNum%5!=0)
			cout << nNum << endl;
		nNum++;
	}
	cout << "程式結束!! " << endl;

	return 0;
}
