#include <iostream>
#include "ToughPack.H"

using namespace std;

ToughPack::ToughPack(double lengthValue, double breadthValue, double heightValue): Box(lengthValue, breadthValue, heightValue)
{

}
//==================================================================================
double ToughPack::volume(const int i) const
{
	cout << "Parameter = " << i << endl;

	return 0.85 * length * breadth * height;
}
