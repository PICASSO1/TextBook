#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	const double pi(3.14159265);

	for(double radius(0.2); radius<=3.0; radius+=0.2)
	{
		cout << "radius = " << setw(12) << radius
			 << " area = " << setw(12) << pi * radius * radius << endl;
	}

	return 0;
}
