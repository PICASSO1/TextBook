#include <iostream>
#include "Vessel.H"
#include "Box.H"
#include "Can.H"
#include "Carton.H"
#include "ToughPack.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Box aBox(40, 30, 20);
	Can aCan(10, 3);
	Carton aCarton(40, 30, 20);
	ToughPack hardcase(40, 30, 20);

	Vessel *pVessels[] = {&aBox, &aCan, &aCarton, &hardcase};

	for(int i(0); i<(sizeof(pVessels)/sizeof(pVessels[0])); i++)
		cout << "Volume is " << pVessels[i]->volume() << endl;

	return 0;
}
