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
//==========================================================================
double power(double x, int n)
{
	if(0==n)
		return 1.0;
	if(0<n)
		return x*power(x, n-1);

	return 1.0/power(x, -n);
}
