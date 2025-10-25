// 其實這一題並不是很懂!!
#include <iostream>
#include <cmath>

using namespace std;

double calc(const double &Value, double (*ptr)(double));

int main(void)
{
	double dValue(0);

	cout << "請隨便輸入一個值: ";
	cin >> dValue;

	double (*ptr[3])(double)={sin, cos, tan};
	// 宣告一個指向函式的指標陣列，陣列裡的每一個元素，都是指向函式的指標!!
	cout << "sin(" << dValue << ")= " << calc(dValue, ptr[0]) << endl;
	cout << "cos(" << dValue << ")= " << calc(dValue, ptr[1]) << endl;
	cout << "tan(" << dValue << ")= " << calc(dValue, ptr[2]) << endl;

	return 0;
}
//===============================================================================
double calc(const double &Value, double (*ptr)(double))
{
	return ptr(Value);
}
