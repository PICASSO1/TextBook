#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(void)
{
	const double pi(3.14159265);

	for(double radius(0.2); radius<=3.0; radius+=0.2)
	{
		cout << "radius = " << setprecision(numeric_limits<double>::digits10+1)
			<< scientific << radius
			<< " area = " << setw(10) << setprecision(6) << fixed << pi * radius * radius
			<< endl;
	}

	return 0;
}
