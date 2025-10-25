#include <iostream>
#include <iomanip>

using namespace std;

double changelt(double *pointer_to_it);

int main(void)
{
	double it(5.0), result(changelt(&it));

	cout << "After function execution, it = " << it << endl << "Result returned is " << result << endl;

	return 0;
}
//======================================================================================================
double changelt(double *pointer_to_it)
{
	*pointer_to_it += 10.0;
	cout << "Within function, *pointer_to_it = " << *pointer_to_it << endl;

	return *pointer_to_it;
}