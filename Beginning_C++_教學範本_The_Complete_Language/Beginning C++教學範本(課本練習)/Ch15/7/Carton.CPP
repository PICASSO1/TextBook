#include <iostream>
#include "Carton.H"
#include <cstring>

using namespace std;

Carton::Carton(double lv, double bv, double hv, const char *pStr, double dense, double thick): Box(lv, bv, hv), density(dense), thickness(thick)
{
	pMaterial = new char[strlen(pStr) + 1];
	strcpy(pMaterial, pStr);
	cout << "Carton Contructor!! " << endl;
}

Carton::~Carton(void)
{
	cout << "Carton Destructor!! " << endl;
	delete []pMaterial;
	pMaterial = 0;
}

double Carton::getWeight(void) const
{
	return 2 * (length * breadth + breadth * height + height * length) * thickness * density;
}
