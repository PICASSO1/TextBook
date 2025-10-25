#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lengthValue, double breadthValue, double heightValue)
{
	length = lengthValue;
	breadth = breadthValue;
	height = heightValue;
}
//==================================================================================
double Box::volume(void) const
{
	return length * breadth * height;
}
