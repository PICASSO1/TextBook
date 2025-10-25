#ifndef BOX_H
#define BOX_H
#include <iostream>

using namespace std;

class Box
{
private:
	double L;
	double W;
	double H;
public:
	Box(double l =1.0, double w =1.0, double h =1.0);
	double volume(void) const;
	bool operator<(const Box &X) const;
	friend ostream &operator<<(ostream &out, const Box &box)
	{
		return out << "(" << box.L << ", " << box.W << ", " << box.H << ")";
	}
};

#endif