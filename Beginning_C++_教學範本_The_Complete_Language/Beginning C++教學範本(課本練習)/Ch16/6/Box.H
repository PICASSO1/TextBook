#ifndef BOX_H
#define BOX_H

using namespace std;

class Box
{
public:
	Box(double lengthValue = 1.0, double breadthValue = 1.0, double heightValue = 1.0);
	virtual double volume(void) const = 0;      // «Å§i¬°¯ÂºéµêÀÀ¨ç¼Æ!!
	void ShowVolume(void) const;
protected:
	double length;
	double breadth;
	double height;
};

#endif