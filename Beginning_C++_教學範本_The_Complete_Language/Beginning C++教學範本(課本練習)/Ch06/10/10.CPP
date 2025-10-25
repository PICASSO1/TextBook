#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text=
		"Smith, where Jones had had \"had had\", had had \"had\"."" \"Had had\" had had the examiners' approval.";
	string separators(" ,.\"");
	int start(text.find_first_not_of(separators)), end(0), word_count(0);

	while(start!=string::npos)
	{
		end=text.find_first_of(separators, start+1);
		if(end==string::npos)
			end=text.length();
		cout << text.substr(start, end-start) << endl;
		word_count++;
		start=text.find_first_not_of(separators,end+1);
	}
	cout << "Your string contained " << word_count << " words." << endl;

	return 0;
}
