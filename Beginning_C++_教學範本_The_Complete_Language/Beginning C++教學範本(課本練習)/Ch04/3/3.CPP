#include <iostream>

using namespace std;

int main(void)
{
	char letter('\0');

	cout << "Enter a letter: ";
	cin >> letter;

	if(letter >= 'A')
	{
		if(letter <= 'Z')
		{
			cout << "You entered an upper case letter." << endl;
			return 0;
		}
	}
	if(letter >= 'a')
	{
		if(letter <= 'z')
		{
			cout << "You entered an lower case letter." << endl;
			return 0;
		}
	}
	cout << "You didn't enter a letter!! " << endl;

	return 0;
}
