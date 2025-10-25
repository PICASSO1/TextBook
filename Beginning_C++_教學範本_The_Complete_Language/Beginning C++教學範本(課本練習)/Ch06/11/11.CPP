#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text;

	cout << "Enter a string terminated by #: " << endl;
	getline(cin, text, '#');

	string word;
	cout << "Enter the word to be replaced: ";
	cin >> word;

	string replacement;
	cout << "Enter the replacement word: ";
	cin >> replacement;

	if(word==replacement)
	{
		cout << "The word and its replacement are the same." << cout << "Operation aborted." << cout;
		exit(1);
	}
	int start(text.find(word));
	while(start!=string::npos)
	{
		text.replace(start, word.length(), replacement);
		start=text.find(word, start+replacement.length());
	}
	cout << "Your string is now: " << endl << text << endl;

	return 0;
}
