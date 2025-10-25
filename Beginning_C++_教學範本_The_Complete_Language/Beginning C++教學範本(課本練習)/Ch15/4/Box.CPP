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
