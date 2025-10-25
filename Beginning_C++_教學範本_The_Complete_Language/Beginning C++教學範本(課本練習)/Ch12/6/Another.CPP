#include <iostream>
#include "Another.H"

using namespace std;

Box::Box(double lengthValue, double breadthValue, double heightValue)
{
	cout << "Box Constructor Called!! " << endl;

	length = lengthValue;
	breadth = breadthValue;
	height = heightValue;

	if(length <= 0)
		length = 1.0;
	if(breadth <= 0)
		breadth =1.0;
	if(height <= 0)
		height = 1.0;
}

double Box::volume(void)
{
	return length * breadth * height;
}
//===================================================================================
double boxSurface(const Box &theBox)
{
	return 2.0 * (theBox.breadth * theBox.height + theBox.breadth * theBox.length + theBox.height * theBox.length);
}