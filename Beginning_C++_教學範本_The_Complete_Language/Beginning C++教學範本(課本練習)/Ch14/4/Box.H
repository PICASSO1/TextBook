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
	Box(double aLength = 1.0 , double aBreadth = 1.0, double aHeight = 1.0);      // Constructor
	double volume(void) const;
	inline double getLength(void) const  { return length;  }
	inline double getBreadth(void) const { return breadth; }
	inline double getHeight(void) const  { return height;  }
	bool operator<(const Box &aBox) const;
	bool operator<(const double aValue) const;
	Box operator+(const Box &aBox) const;
};

#endif