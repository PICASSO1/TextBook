#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	const int size(5);
	int values[size]={1, 2, 3};
	double junk[size];

	for(int i(0); i<size; i++)
		cout << " " << setw(12) << values[i];
	cout << endl;

	for(int j(0); j<size; j++)
		cout << " " << setw(12) << junk[j];
	cout << endl;

	return 0;
}
