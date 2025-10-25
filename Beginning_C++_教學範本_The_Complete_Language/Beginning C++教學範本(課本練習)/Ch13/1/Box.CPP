#include <iostream>
#include "Box.H"

using namespace std;

double Box::volume(void) const
{
	return length * breadth * height;
}
//=================================================================
int Box::compareVolume(const Box &otherBox) const
{
	double vol1(this->volume()), vol2(otherBox.volume());

	return vol1> vol2? 1: (vol1< vol2? -1: 0);
}
