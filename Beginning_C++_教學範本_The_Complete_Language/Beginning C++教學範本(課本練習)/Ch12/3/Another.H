#ifndef ANOTHER_H
#define ANOTHER_H

using namespace std;

class Box      // 定義一個自訂的資料型態─類別!!
{
public:
	double length;
	double breadth;
	double height;

//	Box();      // 另一種沒有預設值的建構函數!!
	Box(double lengthValue = 0.0, double breadthValue = 0.0, double heightValue = 0.0);      // 建構函數，用來初始化類別的成員!!
	double volume(void);
};

#endif