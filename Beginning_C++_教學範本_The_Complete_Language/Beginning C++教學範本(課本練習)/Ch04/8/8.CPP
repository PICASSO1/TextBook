#include <iostream>

using namespace std;

int main(void)
{
	int choice(0);

	cout << "Your electronic recipe book is at your service. " << endl
		 << "You can choose from the following delicious dishes: " << endl
		 << "1 Boiled eggs" << endl
	     << "2 Fried eggs" << endl
		 << "3 Scrambed eggs" << endl
		 << "4 Coddled eggs" << endl << endl
		 << "Enter your selection number: ";
	cin >> choice;

	switch(choice)
	{
	    case 1: cout << "Boil some eggs" << endl;
			    break;
	    case 2: cout << "Fry some eggs" << endl;
			    break;
	    case 3: cout << "Scramble some eggs" << endl;
			    break;
	    case 4: cout << "Coddle some eggs" << endl;
			    break;
		default: cout << "You entered a wrong number, try raw eggs." << endl;
			     break;
	}
	return 0;
}
