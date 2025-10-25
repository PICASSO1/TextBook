#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	char letter('\0');

	cout << "Enter a letter: ";
	cin >> letter;

	if(isupper(letter))
	{
		cout << "You enter a capital letter." << endl;
		cout << "Converting to lower case we get: "
			 << static_cast<char>(tolower(letter)) << endl;
		return 0;
	}
	if(islower(letter))
	{
		cout << "You enter a small letter." << endl;
		cout << "Converting to upper case we get: "
			 << static_cast<char>(toupper(letter)) << endl;
		return 0;
	}
	cout << "You didn't enter a ltter!! " << endl;

	return 0;
}
