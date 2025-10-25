#include <iostream>

using namespace std;

int main(void)
{
	const int maxlength(100);
	char text[maxlength]={0};

	cout << "Enter a line of text: " << endl;
	cin.getline(text, maxlength, '\n');

	cout << "Yor entered: " << text << endl;
	int vowels(0), consonants(0);
	for(int i(0); text[i]!='\0'; i++)
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
			}
		}
	}
	cout << "Your input contained " << vowels << " vowels and " << consonants << " consonants."
		 << endl;

	return 0;
}
