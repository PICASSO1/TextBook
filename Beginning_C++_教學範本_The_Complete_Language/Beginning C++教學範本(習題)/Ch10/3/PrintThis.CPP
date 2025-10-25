#include <iostream>
#include <string>
#include "Print.H"

namespace std
{
	void PrintThis(const string &s)
	{
		cout << "PrintThis Version: ";
		print1::Print(s);

		return;
	}
}

