#include <iostream>
#include "Animal.H"

using namespace std;

Animal::Animal(string Name, double WEIGHT)
{
	strName = Name;
	nWeight = WEIGHT;
}

void Animal::who(void) const
{
	cout << "Animal's who()!! " << endl;
	cout << "Name: " << strName << ", " << "Weight: " << nWeight << endl;
}