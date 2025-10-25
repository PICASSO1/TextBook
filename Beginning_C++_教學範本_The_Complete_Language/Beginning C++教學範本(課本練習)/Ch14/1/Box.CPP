#include <iostream>
#include "Box.H"

using namespace std;

double Box::volume(void) const
{
	return length * breadth * height;
}
//====================================================================
bool Box::operator <(const Box &aBox) const      // Operator Overloading!!
{
	return this->volume() < aBox.volume();
}
