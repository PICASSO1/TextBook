#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text;
	const string separators=" ,.\"\n";
	const int max_words(1000);
	string words[max_words];
	string *pwords[max_words];

	cout << "Enter a string terminated by \"#\": " << endl;
	getline(cin, text, '#');

	int start(text.find_first_not_of(separators));
	int end(0), word_count(0);
	while(start!=string::npos && word_count<max_words)
	{
		end=text.find_first_of(separators, start+1);
		if(end==string::npos)
			end=text.length();
		words[word_count] = text.substr(start, end-start);
		pwords[word_count] = &words[word_count];
		word_count++;
		start = text.find_first_not_of(separators, end+1);
	}
	int lowest(0);
	for(int j(0); j<word_count-1; j++)
	{
		lowest=j;
		for(int i(j+1); i<word_count; i++)
		{
			if(*pwords[i] < *pwords[lowest])
				lowest=i;
		}
		if(lowest!=j)
		{
			string *ptemp = pwords[j];
			pwords[j] = pwords[lowest];
			pwords[lowest] = ptemp;
		}
	}
	for(int k(0); k<word_count; k++)
		cout << endl << *pwords[k];
	cout << endl;

	return 0;
}
