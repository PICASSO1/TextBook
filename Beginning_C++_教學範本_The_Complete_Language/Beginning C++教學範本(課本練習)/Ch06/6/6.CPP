#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string first, second;

	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your second name: ";
	cin >> second;
	
	string sentence="Your full name is ";
	sentence = sentence + first + " " + second + ".";
	cout << endl << sentence << endl;
	cout << "The string contains " << sentence.length() << " characters." << endl;

	return 0;
}
