#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lv, double bv, double hv)
{
	length = lv;
	breadth = bv;
	height = hv;
}

double Box::volume(void)
{
	return length * breadth * height;
}
