#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	cout << setw(5) << 10+20          << endl;
	cout << setw(5) << 10-5           << endl;
	cout << setw(5) << 10-20          << endl;
	cout << setw(5) << 10*20          << endl;
	cout << setw(5) << 10/3           << endl;
	cout << setw(5) << 10%3           << endl;
	cout << setw(5) << 10+20/10-5     << endl;
	cout << setw(5) << (10+20)/(10-5) << endl;
	cout << setw(5) << 10+20/(10-5)   << endl;
	cout << setw(5) << (10+20)/10-5   << endl;
	cout << setw(5) << 4*5/3%4+7/3    << endl;

	return 0;
}
