#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lvalue, double wvalue, double hvalue)
{
	length = lvalue;
	width = wvalue;
	height = hvalue;
}
//===============================================================================================
void Box::showVolume(void) const
{
	cout << "Box usable volume is " << volume() << endl;
}
//===============================================================================================
double Box::volume(void) const
{
	return length * width * height;
}
