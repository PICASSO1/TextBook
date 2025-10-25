#include <iostream>
#include <string>
#include "Animal.H"
#include <iomanip>

using namespace std;

Animal::Animal(string NAME, size_t Weight)
{
//	cout << "Animal Constructor!! " << endl;
	strName = NAME;
	nWeight = Weight;
}
//==========================================================================
void Animal::who(void) const
{
	cout << "Name: " << setw(8) << strName << ", Weight: " << nWeight << ", Sound: ";
	sound();
}
//==========================================================================
Animal::~Animal(void)
{
//	cout << "Animal Destructor!! " << endl;
}
