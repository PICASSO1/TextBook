#include <iostream>
#include "Another.H"

using namespace std;

int main(void)
{
	double data[]={1.5, 4.6, 3.1, 1.1, 3.8, 2.1};

	const int datasize(sizeof(data)/sizeof(double));

	cout << "Mininum double is " << compare::min(data, datasize) << endl;
	cout << "Maxinum double is " << compare::max(data, datasize) << endl;

	return 0;
}
