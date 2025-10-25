#include <iostream>
#include "Box.H"
#include "ToughPack.H"
#include "Carton.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Box *pBox = 0;
	ToughPack hardcase(20.0, 30.0, 40.0);
	pBox = &hardcase;
	cout << "Volume of hardcase is " << pBox->volume() << endl;

	Carton aCarton(20.0, 30.0, 40.0);
	pBox = &aCarton;
	cout << "Volume of aCarton is " << pBox->volume() << endl;

	return 0;
}
