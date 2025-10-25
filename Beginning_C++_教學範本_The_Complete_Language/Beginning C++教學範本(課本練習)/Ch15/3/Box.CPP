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
