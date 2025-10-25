#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
	Box firstBox(17.0, 11.0, 5.0);
	Box Boxes[5];

	cout << "Volume of firstBox = " << firstBox.volume() << endl;

	const int count = sizeof(Boxes) / sizeof(Boxes[0]);
	cout << "The boxes array has " << count << " elements. " << endl;
	cout << "Each element occupies " << sizeof(Boxes[0]) << " bytes. " << endl;

	for(int i(0); i<count; i++)
	{
		cout << "Volumn of boxes["<< i << "] = " << Boxes[i].volume() << endl;
	}

	return 0;
}

