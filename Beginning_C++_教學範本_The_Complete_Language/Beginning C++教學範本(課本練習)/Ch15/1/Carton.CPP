#include <iostream>
#include "Carton.H"
#include <cstring>

using namespace std;

Carton::Carton(const char *pStr)
{
	pMaterial = new char[strlen(pStr) + 1];
	strcpy(pMaterial, pStr);
}

Carton::~Carton(void)
{
	delete []pMaterial;
	pMaterial = 0;
}
