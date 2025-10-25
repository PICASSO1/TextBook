#include <iostream>

using namespace std;

struct Box
{
	double length;
	double breadth;
	double height;
	double volume();
};

int main(int argc, char *argv, char *envp)
{
	struct Box aBox = {10, 20, 30};
	struct Box *pBox = 0;
	pBox = &aBox;

	cout << "Volume of aBox is " << pBox->volume() << endl;

	struct Box *pdynBox = new (struct Box); //使用動態記憶體配置，所配置的空間為Box這個結構的大小!!
	pdynBox->height = pBox->height + 5.0;
	pdynBox->length = pBox->length - 3.0;
	pdynBox->breadth = pBox->breadth - 2.0;
	cout << "Volume of Box in the free store is " << pdynBox->volume() << endl;
	delete pdynBox;
	pdynBox = 0;

	return 0;
}
//===================================================================================================
double Box::volume()
{
	return breadth * height * length;
}
