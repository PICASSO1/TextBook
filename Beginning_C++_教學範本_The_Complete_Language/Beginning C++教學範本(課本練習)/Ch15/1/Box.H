#ifndef BOX_H
#define BOX_H

using namespace std;

class Box
{
private:
	double length;
	double breadth;
	double height;
public:
	Box(double lv = 1.0, double bv = 1.0, double hv = 1.0);
	double volume(void);
};

#endif