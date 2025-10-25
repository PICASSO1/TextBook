#include <iostream>

using namespace std;

int main(void)
{
	long number(0L);

	cout << "Enter an integer less than 2 billion: ";
	cin >> number;

	if(number % 2L == 0)
		cout << "Your number is even. " << endl;
	else
		cout << "Your number is odd. " << endl;

	return 0;
}
