#include <iostream>
#include "Carton.H"
#include <cstring>

using namespace std;

Carton::Carton(const char *pStr)
{
	cout << "Carton Constructor!! " << endl;
	pMaterial = new char[strlen(pStr) + 1];
	strcpy(pMaterial, pStr);
}

Carton::~Carton(void)
{
	delete []pMaterial;
	pMaterial = 0;
}
