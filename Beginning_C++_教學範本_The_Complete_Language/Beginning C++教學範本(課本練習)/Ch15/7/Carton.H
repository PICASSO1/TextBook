#ifndef CARTON_H
#define CARTON_H
#include "Box.H"
#include <cstring>

using namespace std;

class Carton: public Box
{
protected:
	char *pMaterial;
	double thickness;
	double density;
public:
	Carton(double lv = 1.0, double bv = 1.0, double hv = 1.0, const char *pStr = "Cardboard", double dense = 0.125, double thick = 0.2);
	~Carton(void);
	double getWeight(void) const;
};

#endif