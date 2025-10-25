//#include <iostream>
#include "stdafx.h"
#include "Another.H"

using namespace std;

Box::Box()
{
	cout << "Default Constructor Called!! " << endl;
	length = breadth = height = 1;
}

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
