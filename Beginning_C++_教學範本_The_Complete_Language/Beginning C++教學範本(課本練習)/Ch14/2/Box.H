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
	Box(double aLength = 0.0, double aBreadth = 0.0, double aHeight = 0.0) // Constructor!!
	{
		length = aLength;
		breadth = aBreadth;
		height = aHeight;
	}
	double volume() const;
	inline double getLength(void) const { return length; }
	inline double getBreadth(void) const { return breadth; }
	inline double getHeight(void) const { return height; }
	bool operator<(const Box &aBox) const;      // Operator Overloading!!
	bool operator<(const double aValue) const;      // Operator Overloading!!
};
//====================================================================
inline bool operator<(const double aValue, const Box &aBox)      // Operator Overloading!!
{
	return aValue < aBox.volume();
}

#endif
