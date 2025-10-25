#include <iostream>
#include "MyTroubles.H"

using namespace std;

Trouble::Trouble(const char *pStr)
{
//	cout << "Trouble Constructor!! " << endl;
	pMessage = pStr;
}
//=====================================================================
const char *Trouble::what(void) const
{
	return pMessage;
}
//=====================================================================
Trouble::~Trouble(void)
{
//	cout << "Trouble Destructor!! " << endl;
}
