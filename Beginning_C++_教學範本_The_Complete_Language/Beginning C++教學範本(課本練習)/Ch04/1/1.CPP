#include <iostream>

using namespace std;

int main(void)
{
	char first(0), second(0);

	cout << "Enter a character: ";
	cin >> first;
	cout << "Enter a second character: ";
	cin >> second;

	cout << "The value of the expression first < second is: " << (first < second) << endl;
	cout << "The value of the expression first == second is: " << (first == second) << endl;

	return 0;
}
