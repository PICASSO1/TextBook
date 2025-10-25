#include <iostream>

using namespace std;

int main(void)
{
	int value(0);

	cout << "Enter an integer between 50 to 100: ";
	cin >> value;
	if(value<50)
		cout << "The value is invalid - it is less than 50." << endl;

	if(value>100)
		cout << "The value is invalid - it is greater than 100." << endl;

	cout << "You entered: " << value << endl;

	return 0;
}
