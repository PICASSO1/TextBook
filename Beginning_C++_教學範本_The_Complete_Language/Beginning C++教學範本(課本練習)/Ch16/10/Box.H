#ifndef BOX_H
#define BOX_H

using namespace std;

class Box
{
public:
	Box(double lengthValue = 1.0, double breadthValue = 1.0, double heightValue = 1.0);
	virtual double volume(void) const;
	void ShowVolume(void) const;
	inline double getLength(void) const  { return length;  }
	inline double getBreadth(void) const { return breadth; }
	inline double getHeight(void) const  { return height;  }
protected:
	double length;
	double breadth;
	double height;
};

#endif