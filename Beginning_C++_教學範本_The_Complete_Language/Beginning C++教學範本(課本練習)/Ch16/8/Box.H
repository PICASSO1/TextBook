#ifndef BOX_H
#define BOX_H
#include "Vessel.H"

using namespace std;

class Box: public Vessel
{
public:
	Box(double lengthValue = 1.0, double breadthValue = 1.0, double heightValue = 1.0);
	virtual double volume(void) const;
	~Box(void);
protected:
	double length;
	double breadth;
	double height;
};

#endif