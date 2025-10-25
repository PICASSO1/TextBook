#include "Box.H"

using namespace std;

Box::Box(double l, double w, double h)
{
	L = l;
	W = w;
	H = h;
}
//==============================================================================================
double Box::volume(void) const
{
	return L * W * H;
}
//==============================================================================================
bool Box::operator <(const Box &X) const
{
	return (this->volume()) < (X.volume());
}

