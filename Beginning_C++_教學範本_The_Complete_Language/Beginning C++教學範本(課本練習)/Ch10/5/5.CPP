#include "Another.H"
#include <iostream>
#include "Other.H"
#include <iomanip>

using compare::max;
using compare::min;

int main(void)
{
	double data[]={1.5, 4.6, 3.1, 1.1, 3.8, 2.1};
	int numbers[]={23, 2, 14, 56, 42, 12, 1, 45};

	using namespace std;
	const int datasize(sizeof(data)/sizeof(double));
	cout << "Mininum double is " << min(data, datasize) << endl;
	cout << "Maxinum double is " << max(data, datasize) << endl;

	const int numberssize(sizeof(numbers)/sizeof(int));
	cout << "Mininum integer is " << min(numbers, numberssize) << endl;
	cout << "Maxinum integer is " << max(numbers, numberssize) << endl;

	double newData[numberssize];
	compare::normalize(numbers, newData, numberssize);
	for(int i(0); i<numberssize; i++)
	{
		if(i%5 == 0)
			cout << endl;
		cout << setw(12) << newData[i];
	}
	cout << endl;

	return 0;
}
