#ifndef ANOTHER_H
#define ANOTHER_H

using namespace std;

class Box      // �w�q�@�Ӧۭq����ƫ��A�w���O!!
{
public:
	double length;
	double breadth;
	double height;

	Box();      // �t�@�بS���w�]�Ȫ��غc���!!
	Box(double lengthValue, double breadthValue, double heightValue);      // �غc��ơA�ΨӪ�l�����O������!!
	double volume(void);
};

#endif