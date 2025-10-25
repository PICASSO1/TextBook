#include <iostream>
#include "Box.H"

using namespace std;

double Box::volume(void) const
{
	return length * breadth * height;
}
//====================================================================
bool Box::operator<(const Box &aBox) const
{
	return this->volume() < aBox.volume();
}
//====================================================================
bool Box::operator<(const double aValue) const
{
	return this->volume() < aValue;
}
