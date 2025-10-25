#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double fish_count=20.0;
	double ave_length=9.0/12.0;
	double pond_area=0.0, pond_diameter=0.0;
	const double fish_factor=2.0/0.5;
	const double pi=3.14159265;
	pond_area=fish_count * ave_length * fish_factor;
	pond_diameter=2.0 * sqrt(pond_area / pi);

	cout << "Pond diameter required is "
		 << pond_diameter
		 << " feet."
		 << endl;

	return 0;
}
