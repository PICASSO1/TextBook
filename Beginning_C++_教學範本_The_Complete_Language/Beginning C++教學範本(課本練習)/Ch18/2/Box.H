#ifndef BOX_H
#define BOX_H

using namespace std;

class Box
{
public:
	Box(double lengthValue = 1.0, double widthValue = 1.0, double heightValue = 1.0);
	void showVolume(void) const;
	virtual double volume(void) const;
	inline double getLength(void) const { return length; }
    inline double getWidth(void) const  { return width;  }
    inline double getHeight(void) const { return height; }
protected:
    double length;
    double width;
    double height;
};

#endif