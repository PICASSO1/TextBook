#include <iostream>
#include "Box.H"
#include "ToughPack.H"
#include "Carton.H"

using namespace std;

typedef double Box::* pBoxMeber;

int main(int argc, char *argv[], char *envp[])
{
	pBoxMeber pData = 0;
	Box myBox(20.0, 30.0, 40.0);
	ToughPack hardcase(35.0, 45.0, 55.0);
	Carton aCarton(48.0, 58.0, 68.0);

	pData = &Box::length;
	cout << "length member of myBox is " << myBox.*pData << endl;

	pData = &Box::breadth;
	cout << "breadth member of myBox is " << myBox.*pData << endl;

	pData = &Box::height;
	cout << "height member of myBox is " << myBox.*pData << endl;
	cout << "height member of hardcase is " << hardcase.*pData << endl;
	cout << "height member of aCarton is " << aCarton.*pData << endl;

	Box *pBox = &myBox;
	cout << "height member of myBox is " << pBox->*pData << endl;

	pBox = &hardcase;
	cout << "height member of hardcase is " << pBox->*pData << endl;

	return 0;
}
