#include <iostream>
#include "Another.H"

using namespace std;

Box::Box(void)
{
	cout << "Default Constructor Called!! " << endl;
	length = breadth = height = 1.0;
}

Box::Box(double lengthValue, double breadthValue, double heightValue)
{
	cout << "Box Constructor Called!! " << endl;

	length = lengthValue;
	breadth = breadthValue;
	height = heightValue;

	if(length <= 0)
		length = 1.0;
	if(breadth <= 0)
		breadth =1.0;
	if(height <= 0)
		height = 1.0;
}

double Box::volume(void) const
{
	return length * breadth * height;
}
//===================================================================================
int Box::CompareVolumn(const Box &otherBox) const
{
	double vol1 = this->volume();      // vol1 = 935
	double vol2 = otherBox.volume();   // vol2 = 648

	return vol1 > vol2? 1: (vol1 < vol2? -1: 0); 
}
