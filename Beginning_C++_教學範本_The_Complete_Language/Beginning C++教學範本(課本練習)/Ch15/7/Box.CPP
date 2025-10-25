#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lv, double bv, double hv)
{
	cout << "Box Consructor!! " << endl;
	length = lv;
	breadth = bv;
	height = hv;
}

Box::Box(const Box &aBox): length(aBox.length), breadth(aBox.breadth), height(aBox.height)
{
	cout << "Box Copy Constructor!! " << endl;
}

Box::~Box(void)
{
	cout << "Box Destructor!! " << endl;
}

double Box::volume(void) const
{
	return length * breadth * height;
}
