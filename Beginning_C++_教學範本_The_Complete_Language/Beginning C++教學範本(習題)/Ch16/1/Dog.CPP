#include <iostream>
#include "Dog.H"

using namespace std;

Dog::Dog(string NAME, size_t Weight): Animal(NAME, Weight)
{
//	cout << "Dog Constructor!! " << endl;
}
//==========================================================================
void Dog::sound(void) const
{
	cout << "OunOunOun...." << endl;      // ª¯¥sÁn!!
}
//==========================================================================
Dog::~Dog(void)
{
//	cout << "Dog Destructor!! " << endl;
}
