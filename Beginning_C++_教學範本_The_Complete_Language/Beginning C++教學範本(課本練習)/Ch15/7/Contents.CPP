#include <iostream>
#include "Contents.H"
#include <cstring>

using namespace std;

Contents::Contents(const char *pStr, double weight, double vol): unitweight(weight), volume(vol)
{
	pName = new char[strlen(pStr) + 1];
	strcpy(pName, pStr);
	cout << "Contents Constructor!! " << endl;
}

Contents::~Contents(void)
{
	delete []pName;
	pName = 0;
	cout << "Contents Destructor!! " << endl;
}

double Contents::getWeight(void) const
{
	return volume * unitweight;
}
