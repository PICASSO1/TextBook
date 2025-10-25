#include <iostream>
#include "Box.H"
#include "Carton.H"

using namespace std;

int main(int argv, char *argc[], char *envp[])
{
	Carton myCarton, candyCarton(50.0, 30.0, 20.0, "Thin cardboard");

	cout << "myCarton volume is " << myCarton.volume() << endl;
	cout << "candyCarton volume is " << candyCarton.volume() << endl;

	return 0;
}
