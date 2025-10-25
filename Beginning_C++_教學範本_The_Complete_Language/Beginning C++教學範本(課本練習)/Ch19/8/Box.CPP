#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double lv, double bv, double hv)
{
	length = lv;
	breadth = bv;
	height = hv;
}
//=============================================================================================
Box::~Box(void)
{
}
//=============================================================================================
void Box::ShowVolme(void) const
{
	cout << "Bxo usable volume is " << volume();
}
//=============================================================================================
double Box::volume(void) const
{
	return length * breadth * height;
}
//=============================================================================================
ostream &operator<<(ostream &out, const Box &rBox)
{
	return out << ' ' << rBox.getLength() << ' ' << rBox.getBredth() << ' ' << rBox.getHeight();
}
//=============================================================================================
istream &operator>>(istream &in, const Box &rBox)
{
	return in >> rBox.length >> rBox.breadth >> rBox.height;
}
