#include <iostream>
#include "Box.H"
#include "Carton.H"

using namespace std;

int main(int argv, char *argc[], char *envp[])
{
	Carton candyCarton(20.0, 30.0, 40.0, "Glassine board");
	Carton copyCarton(candyCarton);

	cout << "Volume of candyCarton is " << candyCarton.volume() << endl;
	cout << "Volume of copyCarton is " << copyCarton.volume() << endl;

	return 0;
}
