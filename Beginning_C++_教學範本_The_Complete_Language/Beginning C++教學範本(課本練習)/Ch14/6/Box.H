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
	Box(double aLength = 1.0, double aBreadth = 1.0, double aHeight = 1.0)
	{
		length = aLength > 0.0? aLength: 1.0;
		breadth = aBreadth > 0.0? aBreadth: 1.0;
		height = aHeight > 0.0? aHeight: 1.0;
	}
	double volume(void) const;
	int compareVolume(const Box &otherBox) const;
	inline double getLength(void) const
	{
		return length;
	}
	inline double getBreadth(void) const
	{
		return breadth;
	}
	inline double getHeight(void) const
	{
		return height;
	}
	bool operator<(const Box &aBox) const;
};

#endif