#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
	Box firstBox = {80.0, 50.0, 40.0};
	double firstBoxVolume(firstBox.volume());

	cout << "Size of first Box object is " << firstBox.length << " by " << firstBox.breadth << " by " << firstBox.height << endl;
	cout << "Volume of first Box object is " << firstBoxVolume << endl;

	Box secondBox = firstBox;
	secondBox.length *= 1.1;
	secondBox.breadth *= 1.1;
	secondBox.height *= 1.1;

	cout << "Size of second Box object is " << secondBox.length << " by " << secondBox.breadth << " by " << secondBox.height << endl;
	cout << "Volume of second Box object is " << secondBox.volume() << endl;
	cout << "Increasing the box dimensions by 10% has increased the volume by "
		 << static_cast<long>(secondBox.volume() - firstBoxVolume)*100/firstBoxVolume << "% " << endl;

	return 0;
}
