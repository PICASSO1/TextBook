#include <iostream>
#include "Carton.H"
#include <string>

using namespace std;

Carton::Carton(double lv, double bv, double hv, string material): Box(lv, bv, hv)
{
	pMaterial = new string(material);
}
//==================================================================================
Carton::Carton(const Carton &aCarton)
{
	length = aCarton.length;
	breadth = aCarton.breadth;
	height = aCarton.height;
	pMaterial = new string(*aCarton.pMaterial);
}
//==================================================================================
Carton::~Carton(void)
{
	cout << "Carton Destructor!! " << endl;
	delete pMaterial;
	pMaterial = 0;
}
//==================================================================================
double Carton::volume(void) const
{
	double vol = (length - 0.5) * (breadth - 0.5) * (height - 0.5);

	return vol> 0.0? vol: 0.0;
}
