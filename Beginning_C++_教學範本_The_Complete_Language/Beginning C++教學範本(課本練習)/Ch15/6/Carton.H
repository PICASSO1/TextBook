#ifndef CARTON_H
#define CARTON_H
#include "Box.H"
#include <cstring>

using namespace std;

class Carton: public Box
{
protected:
	char *pMaterial;
public:
	Carton(const char *pStr = "Cardboard");
	Carton(double lv, double bv, double hv, const char *pStr = "Cardboard");
	~Carton(void);
	double volume(void) const;
	Carton(const Carton &aCarton);
};

#endif