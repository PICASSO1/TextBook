#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
	Box firstBox(2.2, 1.1, 0.5);
	Box secondBox(firstBox);

	cout << "Volume of firstBox = " << firstBox.volume() << endl;
	cout << "Volume of secondBox = " << secondBox.volume() << endl;

	return 0;
}
