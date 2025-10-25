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

Box::Box(void): length(1.0), breadth(1.0), height(1.0)
{
	cout << "Default Box Constructor!! " << endl;
}

Box::Box(const Box &aBox): length(aBox.length), breadth(aBox.breadth), height(aBox.height)
{
	cout << "Box Copy Constructor!! " << endl;
}
