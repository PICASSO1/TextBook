#ifndef SIZEBOX_H
#define SIZEBOX_H

class SizeBox
{
private:
	char *pMaterial;
	double length;
	double breadth;
	double height;
public:
	SizeBox(void)
	{
		pMaterial = 0;
		length = 0.0;
		breadth = 0.0;
		height = 0.0;
	}
	SizeBox(double a, double b, double c)
	{
		pMaterial = "CardBoard";
		length = a;
		breadth = b;
		height = c;
	}
	int TotalSize(void);
};

#endif