#include <iostream>
#include <string>
#include "Lion.H"

using namespace std;

Lion::Lion(string Name, double WEIGHT): Animal(Name, WEIGHT)
{

}

void Lion::who(void) const
{
	cout << "Lion's who()!! " << endl;
	cout << "Name: " << strName << ", " << "Weight: " << nWeight << endl;
}
