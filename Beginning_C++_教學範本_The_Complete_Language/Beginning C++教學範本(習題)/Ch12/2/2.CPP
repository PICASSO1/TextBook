#include <iostream>
#include "Integer.H"

using namespace std;

int main(void)
{
	Integer nRet1;
	cout << nRet1.getnRet() << endl;

	Integer nRet2(1);
	cout << nRet2.getnRet() << endl;

	int nRet3 = Call_by_Value(nRet1);
	cout << "這是透過以值傳遞的函數所產生的值: " << nRet3 << endl;

	int nRet4 = Call_by_Reference(nRet2);
	cout << "這是透過以參考值傳遞的函數所產生的值: " << nRet4 << endl;

	return 0;
}
