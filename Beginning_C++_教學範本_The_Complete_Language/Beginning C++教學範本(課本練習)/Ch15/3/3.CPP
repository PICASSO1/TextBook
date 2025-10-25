#include <iostream>
#include "Box.H"
#include "Carton.H"

using namespace std;

int main(int argv, char *argc[], char *envp[])
{
	Box myBox(40.0, 30.0, 20.0);
	Carton myCarton;

	cout << "myCarton volume is " << myCarton.volume() << endl;
//	cout << "myCarton length is " << myCarton.length << endl;

	return 0;
}
