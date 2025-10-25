#include <iostream>
#include "Carton.H"
#include <cstring>

using namespace std;

Carton::Carton(const char *pStr)
{
	pMaterial = new char[strlen(pStr) + 1];
	strcpy(pMaterial, pStr);
	cout << "Carton Contructor 1 " << endl;
}

Carton::Carton(double lv, double bv, double hv, const char *pStr): Box(lv, bv, hv)
{
	pMaterial = new char[strlen(pStr) + 1];
	strcpy(pMaterial, pStr);
	cout << "Carton Contructor 2 " << endl;
}

Carton::~Carton(void)
{
	delete []pMaterial;
	pMaterial = 0;
}

double Carton::volume(void) const
{
	return length * breadth * height;
}

Carton::Carton(const Carton &aCarton): Box(aCarton)
{
	pMaterial = new char[strlen(aCarton.pMaterial) + 1];
	strcpy(pMaterial, aCarton.pMaterial);
	cout << "Carton Copy Constructor!! " << endl;
}