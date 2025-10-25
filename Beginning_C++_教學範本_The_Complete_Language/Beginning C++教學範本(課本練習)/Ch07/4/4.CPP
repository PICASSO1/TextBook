#include <iostream>

using namespace std;

int main(void)
{
	const char *pstar[6] =
	{
	"Mae West", "Arnold Schwarzenegger", "Lassie", "Slim Pickens", "Greta Garbo", "Oliver Hardy"
	};
	const char *pstr="Your lucky star is ";
	int choice(0);

	cout << "Pick a lucky star!! " << "Enter a number between 1 and 6: ";
	cin >> choice;

	if(choice>=1 && choice<=6)
		cout << pstr << pstar[choice-1] << endl;
	else
		cout << "Sorry, you haven't got a luck star." << endl;

	return 0;
}
