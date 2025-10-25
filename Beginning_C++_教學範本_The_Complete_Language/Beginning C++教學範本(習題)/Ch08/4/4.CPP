/*
// 這是EX 8.3 的程式!!
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
*/

// 這是EX 8.2 的程式!!
#include <iostream>
#include <iomanip>

using namespace std;

double power(double x, int n);

int main(void)
{
	for(int i(-3); i<=3; i++)
		cout << setw(10) << power(8.0, i);
	cout << endl;

	return 0;
}
//======================================================================================================
double power(double x, int n)
{
	double result(1.0);

	if(n>=0)
	{
		for(int i(0); i<n; i++)
			result *= x;
	}
	else
	{
		for(int j(0); j<-n; j++)
			result /= x;
	}

	return result;
}
