#include <iostream>

using namespace std;

int main(void)
{
	unsigned int nRet(0U), nBig(0U), nSmall(0U);
	const int nAAA(12);

	cout << "請輸入一個整數的吋數: ";
	cin >> nRet;
	nBig = nRet / nAAA;
	nSmall = nRet % nAAA;
	cout << nRet << "吋等於" << nBig << "呎" << nSmall << "吋" << endl; 

	return 0;
}
