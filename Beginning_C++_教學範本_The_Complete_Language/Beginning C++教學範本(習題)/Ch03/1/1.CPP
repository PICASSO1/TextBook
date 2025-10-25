#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
// 這支程式會將使用者輸入的一個非0的數，轉成倒數後輸出之!!
	double dNum(0), dResult(0);

	while(1)
	{
		cout << "請輸入一個非0的數(0 to exit): ";
		cin >> dNum;
		if(dNum==0)
			break;
		dResult=1/dNum;
		cout << dNum << "的倒數是1/" << dNum << ", 即: "
			 << setprecision(2) << fixed << dResult << endl;
	}
	cout << "程式結束!! " << endl;

	return 0;
}
