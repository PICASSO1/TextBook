#include <iostream>
#include <string>
#include "Print.H"

namespace std
{
	void PrintThat(const string &s)
	{
		cout << "PrintThat Version: ";
		print2::Print(s);

		return;
	}
}

