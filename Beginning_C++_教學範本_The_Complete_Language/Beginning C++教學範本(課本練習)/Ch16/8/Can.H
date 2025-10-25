#ifndef CAN_H
#define CAN_H
#include "Vessel.H"

using namespace std;

class Can: public Vessel
{
public:
	Can(double canDiameter, double canHeight);
	virtual double volume(void) const;
	~Can(void);
protected:
	double diameter;
	double height;
	static const double pi;
};

#endif