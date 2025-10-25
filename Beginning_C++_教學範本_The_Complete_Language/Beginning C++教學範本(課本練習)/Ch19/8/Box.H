#ifndef BOX_H
#define BOX_H
#include <iostream>

using namespace std;

class Box
{
public:
	Box(double lv= 1, double bv = 1, double hv = 1);
	virtual ~Box(void);
	void ShowVolme(void) const;
	virtual double volume(void) const;
	friend ostream &operator<<(ostream &out, const Box &rBox);
	friend istream &operator>>(istream &in, const Box &rBox);
	inline double getLength() const { return length; }
	inline double getBredth() const { return breadth; }
	inline double getHeight() const { return height; }
protected:
	double length;
	double breadth;
	double height;
};

#endif