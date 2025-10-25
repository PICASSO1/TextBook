#include <iostream>
#include "Cow.H"

using namespace std;

Cow::Cow(string NAME, size_t Weight): Animal(NAME, Weight)
{
//	cout << "Cow Constructor!! " << endl;
}
//==========================================================================
void Cow::sound(void) const
{
	cout << "MoMoMo...." << endl;      // ¤û¥sÁn!!
}
//==========================================================================
Cow::~Cow(void)
{
//	cout << "Cow Destructor!! " << endl;
}
