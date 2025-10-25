#include <iostream>

using namespace std;


struct Box      // 定義一個自訂的資料型態─結構!!
{
	double length;
	double breadth;
	double height;
};

double volume(const Box &aBox);

int main(int argc, char *argv[], char *envp)
{
	struct Box firstBox = {80.0, 50.0, 40.0};
	double firstBoxVolume(volume(firstBox));

	cout << "Size of first Box object is " << firstBox.length << " by " << firstBox.breadth << " by " << firstBox.height << endl;
	cout << "Volume of first Box object is " << firstBoxVolume << endl;

	struct Box secondBox = firstBox;
	secondBox.length *= 1.1;
	secondBox.breadth *= 1.1;
	secondBox.height *= 1.1;

	cout << "Size of second Box object is " << secondBox.length << " by " << secondBox.breadth << " by " << secondBox.height << endl;
	cout << "Volume of second Box object is " << volume(secondBox) << endl;
	cout << "Increasing the box dimensions by 10% has increased the volume by "
		 << static_cast<long>(volume(secondBox) - firstBoxVolume)*100/firstBoxVolume << "% " << endl;

	return 0;
}
//==========================================================================================================
double volume(const Box &aBox)
{
	return aBox.breadth * aBox.height * aBox.length;
}