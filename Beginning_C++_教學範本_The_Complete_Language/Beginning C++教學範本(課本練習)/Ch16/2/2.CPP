#include <iostream>
#include "Box.H"
#include "ToughPack.H"
#include "Carton.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Box myBox(20.0, 30.0, 40.0);
	ToughPack hardcase(20.0, 30.0, 40.0);
	Carton aCarton(20.0, 30.0, 40.0);

	myBox.ShowVolume();
	hardcase.ShowVolume();
	aCarton.ShowVolume();

	Box *pBox = &myBox;
	cout << "myBox volume through pBox is " << pBox->volume() << endl;
	pBox->ShowVolume();

	pBox = &hardcase;
	cout << "hardcase volume through pBox is " << pBox->volume() << endl;
	pBox->ShowVolume();

	pBox = &aCarton;
	cout << "aCarton volume through pBox is " << pBox->volume() << endl;
	pBox->ShowVolume();

	return 0;
}
