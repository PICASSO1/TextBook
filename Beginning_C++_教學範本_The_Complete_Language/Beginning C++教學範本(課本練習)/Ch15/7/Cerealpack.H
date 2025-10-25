#ifndef CEREALPACK_H
#define CEREALPACK_H
#include <iostream>
#include "Carton.H"
#include "Contents.H"

using namespace std;

class Cerealpack: public Carton, public Contents
{
public:
	Cerealpack(double length, double breadth, double height, const char *cerealType);
	~Cerealpack(void);
};

#endif