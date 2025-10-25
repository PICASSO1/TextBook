#include <iostream>
#include "Box.H"

using namespace std;

Box::Box(double aLength, double aBreadth, double aHeight)
{
	double maxSide = aLength> aBreadth? aLength: aBreadth;
	double minSide = aLength< aBreadth? aLength: aBreadth;

	length = maxSide> 0.0? maxSide: 1.0;
	breadth = minSide> 0.0? minSide: 1.0;
	height = aHeight> 0.0? aHeight: 1.0;
}
//==========================================================================
double Box::volume(void) const
{
	return length * breadth * height;
}
//==========================================================================
bool Box::operator <(const Box &aBox) const
{
	return this->volume() < aBox.volume();
}
//==========================================================================
bool Box::operator <(const double aValue) const
{
	return this->volume() < aValue;
}
//==========================================================================
Box Box::operator +(const Box &aBox) const
{
	return Box(length> aBox.getLength()? length: aBox.getLength(), 
		       breadth> aBox.getBreadth()? breadth: aBox.getBreadth(), 
			   height+aBox.height );
}
