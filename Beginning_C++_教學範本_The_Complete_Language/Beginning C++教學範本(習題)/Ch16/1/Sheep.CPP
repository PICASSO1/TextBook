#include <iostream>
#include "Sheep.H"

using namespace std;

Sheep::Sheep(string NAME, size_t Weight): Animal(NAME, Weight)
{
//	cout << "Sheep Constructor!! " << endl;
}
//==========================================================================
void Sheep::sound(void) const
{
	cout << "MaiMaiMai...." << endl;      // ¦Ï¥sÁn!!
}
//==========================================================================
Sheep::~Sheep(void)
{
//	cout << "Sheep Destruvtor!! " << endl;
}
