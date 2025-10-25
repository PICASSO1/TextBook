#include <iostream>

using namespace std;

int main(void)
{
	char ch=0;
	int ch_value=0;

	cout << "Enter a character: " << endl;
	cin >> ch;
	ch_value=ch;
	cout << endl << ch << " is " << ch_value;
	ch_value=++ch;
	cout << endl << ch << " is " << ch_value << endl;

	return 0;
}
