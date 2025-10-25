#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	double dValue1(0), dValue2(0), dValue3(0);
	double dResult1(0), dResult2(0), dResult3(0);

	cout << "這支程式會計算三個數的平方值!!" << endl;
	cout << "請輸入三個數: ";
	cin >> dValue1 >> dValue2 >> dValue3;

	dResult1 = dValue1 * dValue1;
	dResult2 = dValue2 * dValue2;
	dResult3 = dValue3 * dValue3;
	cout << setprecision(2) << fixed << dValue1 << " 的平方值為: " << dResult1 << endl;
	cout << setprecision(2) << fixed << dValue2 << " 的平方值為: " << dResult2 << endl;
	cout << setprecision(2) << fixed << dValue3 << " 的平方值為: " << dResult3 << endl;

	return 0;
}
