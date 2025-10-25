#include <iostream>
#include "SizeBox.H"

using namespace std;

int main(void)
{
	SizeBox box;
	SizeBox boxes[10];

	cout << "The data members of a Box object occupy " << box.TotalSize() << " bytes. " << endl;
	cout << "A single Box object occupies " << sizeof(SizeBox) << "bytes. " << endl;
	cout << "An array of 10 Box objects occupies " << sizeof(boxes) << " bytes. " << endl;
	
	return 0;
}