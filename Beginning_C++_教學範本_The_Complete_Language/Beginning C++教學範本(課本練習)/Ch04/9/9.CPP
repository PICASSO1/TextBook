#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	char letter('\0');

	cout << "Enter a letter: ";
	cin >> letter;

	if(isalpha(letter))
	{
		switch(tolower(letter))
		{
		    case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': cout << "You entered a vowel." << endl;
				      break;
			default: cout << "You entered a consonant. " << endl;
				     break;
		}
	}
	else
		cout << "You didn't enter a letter. " << endl;

	return 0;
}
