#ifndef TOUGHPACK_H
#define TOUGHPACK_H
#include "Box.H"

using namespace std;

class ToughPack: public Box
{
public:
	ToughPack(double lengthValue, double breadthValue, double heightValue);
	double volume(void) const;
};

#endif