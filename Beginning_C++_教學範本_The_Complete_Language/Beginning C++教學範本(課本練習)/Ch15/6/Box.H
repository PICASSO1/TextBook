#ifndef BOX_H
#define BOX_H

using namespace std;

class Box
{
protected:
	double length;
	double breadth;
	double height;
public:
	Box(void);
	Box(double lv, double bv, double hv);
	Box(const Box &aBox);
	~Box(void);
};

#endif