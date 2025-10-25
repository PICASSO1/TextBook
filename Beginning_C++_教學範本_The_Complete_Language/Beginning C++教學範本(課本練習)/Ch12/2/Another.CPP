#include <iostream>
#include "Another.H"

using namespace std;

Box::Box(double lengthValue, double breadthValue, double heightValue)
{
	cout << "Box Constructor Called!! " << endl;

	length = lengthValue;
	breadth = breadthValue;
	height = heightValue;
}

double Box::volume(void)
{
	return length * breadth * height;
}
