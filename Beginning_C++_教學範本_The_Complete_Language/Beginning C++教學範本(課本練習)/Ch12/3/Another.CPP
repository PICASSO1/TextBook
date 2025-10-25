#include <iostream>
#include "Another.H"

using namespace std;
/*
Box::Box()
{
	cout << "Default Constructor Called!! " << endl;
	length = breadth = height = 0;
}
*/
/*
Box::Box(double lengthValue, double breadthValue, double heightValue)
{
	cout << "Box Constructor Called!! " << endl;

	length = lengthValue;
	breadth = breadthValue;
	height = heightValue;
}
*/
// 使用初值串列，來初始化類別成員!!

Box::Box(double lengthValue, double breadthValue, double heightValue): length(lengthValue), breadth(breadthValue), height(heightValue)
{
	cout << "Box Constructor Called!! " << endl;
}

double Box::volume(void)
{
	return length * breadth * height;
}
