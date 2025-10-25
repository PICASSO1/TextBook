#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
//	Box firstBox = {80.0, 50.0, 40.0};
	Box firstBox(80.0, 50.0, 40.0);
	double firstBoxVolume(firstBox.volume());

	cout << "Size of first Box object is " << firstBox.length << " by " << firstBox.breadth << " by " << firstBox.height << endl;
	cout << "Volume of first Box object is " << firstBoxVolume << endl;

	return 0;
}
