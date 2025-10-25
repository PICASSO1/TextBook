#ifndef CARTON_H
#define CARTON_H
#include "Box.H"
#include <cstring>

using namespace std;

class Carton: public Box
{
private:
	char *pMaterial;
public:
	Carton(const char *pStr = "Cardboard");
	~Carton(void);
};

#endif