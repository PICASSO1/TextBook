#include <iostream>
#include "Box.H"
#include "ToughPack.H"
#include "Carton.H"

using namespace std;

typedef double (Box::*pBoxFunction)(void) const;

int main(int argc, char *argv[], char *envp[])
{
	pBoxFunction pGet = 0;
	Box myBox(20.0, 30.0, 40.0);
	ToughPack hardcase(35.0, 45.0, 55.0);
	Carton aCarton(48.0, 58.0, 68.0);

	pGet = &Box::getLength;
	cout << "length member of myBox is " << (myBox.*pGet)() << endl;

	pGet = &Box::getBreadth;
	cout << "breadth member of myBox is " << (myBox.*pGet)() << endl;

	pGet = &Box::getHeight;
	cout << "height member of myBox is " << (myBox.*pGet)() << endl;
	cout << "height member of hardcase is " << (hardcase.*pGet)() << endl;
	cout << "height member of aCarton is " << (aCarton.*pGet)() << endl;

	Box *pBox = &myBox;
	cout << "height member of myBox is " << (pBox->*pGet)() << endl;

	pBox = &hardcase;
	cout << "height member of hardcase is " << (pBox->*pGet)() << endl;

	return 0;
}
