#include <iostream>
#include "ToughPack.H"

using namespace std;

ToughPack::ToughPack(double lengthValue, double breadthValue, double heightValue): Box(lengthValue, breadthValue, heightValue)
{

}
//==================================================================================
double ToughPack::volume(void) const
{
	return 0.85 * length * breadth * height;
}
//==================================================================================
ToughPack::~ToughPack(void)
{
	cout << "ToughPack Destructor!! " << endl;
}
