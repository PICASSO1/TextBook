#include <iostream>

using namespace std;

int main(void)
{
	const int inches_per_foot=12;
	const int foot_per_yard=3;
	int yards=0, feet=0, inches=0;

	cout << "Enter a length as yards, feet, and inches: " << endl;
	cin >> yards >> feet >> inches;

	cout << "Length in inches is "
		 << inches + inches_per_foot * (feet + foot_per_yard * yards) << endl;

	return 0;
}
