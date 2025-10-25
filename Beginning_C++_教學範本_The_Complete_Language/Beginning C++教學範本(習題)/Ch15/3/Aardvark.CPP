#include <iostream>
#include "Aardvark.H"

using namespace std;

Aardvark::Aardvark(string Name, double WEIGHT): Animal(Name, WEIGHT)
{

}

void Aardvark::who(void) const
{
	cout << "Aardvark's who()!! " << endl;
	cout << "Name: " << strName << ", " << "Weight: " << nWeight << endl;
}
