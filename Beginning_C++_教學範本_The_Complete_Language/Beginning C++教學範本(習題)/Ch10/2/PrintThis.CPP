#include <iostream>
#include <string>
#include "Print.H"

namespace std
{
	void PrintThis(const string &s)
	{
		cout << "PrintThis Version: ";
		Print(s);

		return;
	}
}

