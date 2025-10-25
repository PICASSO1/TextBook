#ifndef VESSEL_H
#define VESSEL_H

using namespace std;

class Vessel
{
public:
	virtual double volume(void) const = 0;
	virtual ~Vessel(void);
};

#endif