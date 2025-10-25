#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lv, double bv, double hv)
{
	cout << "Box Constructor!! " << endl;
	length = lv;
	breadth = bv;
	height = hv;
}

double Box::volume(void) const
{
	return length * breadth * height;
}
