#include <iostream>
#include <cstring>
#include "ErrorMessage.H"

using namespace std;

int main(void)
{
	ErrorMessage warning("There is a serious problem here. "), standard;

	cout << "warning contains - " << warning.what() << endl;
	cout << "standard contains - " << standard.what() << endl;

	standard = warning;
	cout << "After assigning the value of warning, standard contains - "
		 << standard.what() << endl;
	cout << "Resetting warning, not standard " << endl;
	
	warning.resetMessage();
	cout << "warnint now contains - " << warning.what() << endl;
	cout << "standard now contains - " << standard.what() << endl;

	return 0;
}
