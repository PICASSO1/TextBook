#ifndef ANOTHER_H
#define ANOTHER_H

using namespace std;

class Box      // 定義一個自訂的資料型態─類別!!
{
public:
	double length;
	double breadth;
	double height;

	double volume()
	{
		return length * breadth * height;
	}
};

#endif