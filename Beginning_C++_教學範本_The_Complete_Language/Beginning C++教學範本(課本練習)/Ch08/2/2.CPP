#include <iostream>
#include <iomanip>

using namespace std;

double changelt(double it);

int main(void)
{
	double it(5.0), result(changelt(it));

	cout << "After function execution, it = " << it << endl << "Result returned is " << result << endl;

	return 0;
}
//======================================================================================================
double changelt(double it)
{
	it += 10.0;
	cout << "Within function, it = " << it << endl;

	return it;
}
