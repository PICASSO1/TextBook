#include <iostream>
#include <iomanip>

using namespace std;

double larger(double a, double b);
long  &larger(long &a, long &b);

int main(void)
{
	cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;

	int value1(35), value2(45);

	cout << "Larger of " << value1 << "and "<< value2 << " is "
		 << larger(static_cast<long>(value1), static_cast<long>(value2)) << endl;

	return 0;
}
//=========================================================================================
double larger(double a, double b)
{
	cout << "Double Version ";

	return a>b? a:b;
}
//=========================================================================================
long &larger(long &a, long &b)
{
	cout << "Long Reference Version ";

	return a>b? a:b;
}