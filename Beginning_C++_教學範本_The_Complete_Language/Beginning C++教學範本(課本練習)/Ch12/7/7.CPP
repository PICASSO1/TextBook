#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
	Box firstBox(17.0, 11.0, 5.0);
	Box secondBox(9.0, 18.0, 4.0);

	cout << "The first box is "
	     << (firstBox.CompareVolumn(secondBox) >= 0? "": "not")
		 << "greater than the second box. " << endl;

	cout << "Volume of firstBox = " << firstBox.volume() << endl;
	cout << "Volume of secondBox = " << secondBox.volume() << endl;

	return 0;
}

