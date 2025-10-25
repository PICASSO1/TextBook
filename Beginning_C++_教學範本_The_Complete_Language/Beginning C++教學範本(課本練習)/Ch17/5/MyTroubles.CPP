#include <iostream>
#include "MyTroubles.H"

using namespace std;

Trouble::Trouble(const char *pStr)
{
//	cout << "Trouble Constructor!! " << endl;
	pMessage = pStr;
}
//-------------------------------------------------------------------
Trouble::~Trouble(void)
{
//	cout << "Trouble Destructor!! " << endl;
}
//-------------------------------------------------------------------
const char *Trouble::what(void) const
{
	return pMessage;
}
//===================================================================
MoreTrouble::MoreTrouble(const char *pStr): Trouble(pStr)
{
//	cout << "More Constructor!! " << endl;
}
//===================================================================
BigTrouble::BigTrouble(const char *pStr): MoreTrouble(pStr)
{
//	cout << "BigTrouble Constructor!! " << endl;
}
