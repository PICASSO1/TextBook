#include <iostream>
#include "Can.H"

using namespace std;

const double Can::pi = 3.14159265;

Can::Can(double canDiameter, double canHeight)
{
	diameter = canDiameter;
	height = canHeight;
}
//==================================================================================
double Can::volume(void) const
{
	return pi * diameter * diameter * height / 4;
}
