#include <iostream>
#include "Box.H"
#include "ToughPack.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Box myBox(20.0, 30.0, 40.0);
	ToughPack hardcase(20.0, 30.0, 40.0);

	myBox.ShowVolume();
	hardcase.ShowVolume();

	cout << "hardcase volume is " << hardcase.volume() << endl;
	Box *pBox = &hardcase;
	cout << "hardcase volume through pBox is " << pBox->volume() << endl;

	return 0;
}
