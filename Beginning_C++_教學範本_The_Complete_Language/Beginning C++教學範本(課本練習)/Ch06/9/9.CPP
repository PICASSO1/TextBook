#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text=
		"Smith, where Jones had had \"had had\", had had \"had\"."" \"Had had\" had had the examiners' approval.";
	string word("had");

	cout << "The string is: " << endl << text << endl;
	int count(0);
	for(int index(0); (index=text.find(word, index))!=string::npos; index+=word.length(), count++)
		;
	cout << "Your text contained " << count << " occurrences of \"" << word << "\"." << endl;

	return 0;
}
