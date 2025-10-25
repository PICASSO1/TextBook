#ifndef ANOTHER_H
#define ANOTHER_H

using namespace std;

class Box      // 定義一個自訂的資料型態─類別!!
{
private:
	double length;
	double breadth;
	double height;

public:
	Box(double lengthValue = 0.0, double breadthValue = 0.0, double heightValue = 0.0);
	double volume(void) const;
	int CompareVolumn(const Box &otherBox) const;
};

#endif