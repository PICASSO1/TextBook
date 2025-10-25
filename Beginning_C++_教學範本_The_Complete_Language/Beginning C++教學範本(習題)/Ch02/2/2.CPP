#include <iostream>
#include <iomanip>
#define PI 3.14

using namespace std;

int main(void)
{
	double dValue(0), dResult(0);
	unsigned int nRet(0U);

	cout << "請輸入一個圓的半徑: ";
	cin >> dValue;
	cout << "請問欲精準至小數點後幾位: ";
	cin >> nRet;
	dResult = dValue * dValue * PI;

	cout << "半徑為" << dValue << "的圓，面積為(計算至小數點後二位): "
		 << setw(4) << setprecision(nRet) << fixed << dResult << endl;

	return 0;
}
