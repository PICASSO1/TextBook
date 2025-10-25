#include <iostream>
#include "Box.H"
#include "Carton.H"

using namespace std;

int main(int argv, char *argc[], char *envp[])
{
	Box myBox(40.0, 30.0, 20.0);
	Carton myCarton;
	Carton CandyCarton("Thin cardboard");

	cout << "myBox volume is " << myBox.volume() << endl;
	cout << "myCarton volume is " << myCarton.volume() << endl;
	cout << "CandyCarton volume is " << CandyCarton.volume() << endl;

	return 0;
}
