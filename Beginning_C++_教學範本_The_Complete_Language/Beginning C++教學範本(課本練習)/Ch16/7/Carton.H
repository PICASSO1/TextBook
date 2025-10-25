#ifndef CARTON_H
#define CARTON_H
#include "Box.H"
#include <string>

using namespace std;

class Carton: public Box
{
private:
	string *pMaterial;
public:
	Carton(double lv, double bv, double hv, string material = "Cardboard");
	Carton(const Carton &aCarton);
	~Carton(void);
	virtual double volume(void) const;
};

#endif