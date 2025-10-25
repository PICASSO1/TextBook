#include <iostream>
#include "Box.H"
#include "Carton.H"

using namespace std;

int main(int argv, char *argc[], char *envp[])
{
	Box myBox(40.0, 30.0, 20.0);
	Carton myCarton;
	Carton CandyCarton("Thin cardboard");

	cout << "myBox occupies " << sizeof(myBox) << " bytes. " << endl;
	cout << "myCarton occupies " << sizeof(myCarton) << " bytes. " << endl;
	cout << "CandyCarton occupies " << sizeof(CandyCarton) << " bytes. " << endl;

	cout << "CandyCarton.volume() = " << CandyCarton.volume() << endl;

	return 0;
}
