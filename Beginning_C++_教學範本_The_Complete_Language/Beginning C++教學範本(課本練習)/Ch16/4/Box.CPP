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
double Box::volume(const int i) const
{
	cout << "Parameter = " << i << endl;

	return length * breadth * height;
}
//==================================================================================
void Box::ShowVolume(void) const
{
	cout << "Box usable volume is " << volume() << endl;
}
