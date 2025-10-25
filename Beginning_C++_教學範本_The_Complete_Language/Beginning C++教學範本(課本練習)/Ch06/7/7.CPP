#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
	string text;

	cout << "Enter a line of text: ";
	getline(cin, text, '.');

	int vowels(0), consonants(0);
	for(int i(0); i<text.length(); i++)
	{
		if(isalpha(text[i]))
		{
			switch(tolower(text[i]))
			{
			    case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u': vowels++;
					      break;
				default: consonants++;
						 break;
			}
		}
	}
	cout << "Your input contained: " << vowels << " vowels and " << consonants << " consonants."
		 << endl;

	return 0;
}
