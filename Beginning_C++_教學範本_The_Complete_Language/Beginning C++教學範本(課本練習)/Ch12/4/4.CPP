#include <iostream>
#include "Another.H"

using namespace std;

int main(int argc, char *argv[], char *envp)
{
	Box firstBox(2.2, 1.1, 0.5), secondBox;
	Box *pthirdBox = 0;
	pthirdBox = new Box(15.0, 20.0, 8.0);

	cout << "Volume of firstBox = " << firstBox.volume() << endl;
	cout << "Volume of secondBox = " << secondBox.volume() << endl;
	cout << "Volume of thirdBox = " << pthirdBox->volume() << endl;
	cout << "ThirdBox size is " << pthirdBox->getBreadth() << " by " << pthirdBox->getHeight() << " by " << pthirdBox->getLength();
	cout << endl;

	delete pthirdBox;
	pthirdBox = 0;

	return 0;
}
