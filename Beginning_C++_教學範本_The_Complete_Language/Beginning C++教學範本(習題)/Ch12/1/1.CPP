#include <iostream>
#include "Integer.H"

using namespace std;

int main(void)
{
	Integer nRet1;
	cout << "這是透過建構函數初始化的值: " << nRet1.GetnRet() << endl;

	Integer nRet2(1);
	cout << "這是直接初始化物件的值: " << nRet2.GetnRet() << endl;

	Integer nRet3;
	nRet3.SetnRet(2);
	cout << "這是透過成員函數來設定類別成員的值: " << nRet3.GetnRet() << endl;

	return 0;
}
