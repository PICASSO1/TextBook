#include <iostream>
#include "Another.H"

using namespace std;

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
/* 使用初值串列，來初始化類別成員!!
Box::Box(double lengthValue, double breadthValue, double heightValue): length(lengthValue), breadth(breadthValue), height(heightValue)
{
	cout << "Box Constructor Called!! " << endl;
}
*/
double Box::volume(void)
{
	return length * breadth * height;
}

double Box::getLength(void)
{
	return length;
}

double Box::getBreadth(void)
{
	return breadth;
}

double Box::getHeight(void)
{
	return height;
}
