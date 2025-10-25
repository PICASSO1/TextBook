#include <iostream>

using namespace std;

int main(void)
{
	const char *pstar1 = "Mae West";
	const char *pstar2 = "Arnold Schwarzenegger";
	const char *pstar3 = "Lassie";
	const char *pstar4 = "Slim Pickens";
	const char *pstar5 = "Greta Garbo";
	const char *pstar6 = "Oliver Hardy";
	const char *pstr = "Your lucky star is ";
	int choice(0);

	cout << "Pick a lucky star!! " << "Enter a number between 1 and 6: ";
	cin >> choice;
	switch(choice)
	{
	    case 1: cout << pstr << pstar1;
			    break;
	    case 2: cout << pstr << pstar2;
			    break;
		case 3: cout << pstr << pstar3;
			    break;
	    case 4: cout << pstr << pstar4;
			    break;
	    case 5: cout << pstr << pstar5;
			    break;
	    case 6: cout << pstr << pstar6;
			    break;
		default: cout << "Sorry, you haven't got a luck star.";
			     break;
	}
	cout << endl;

	return 0;
}
