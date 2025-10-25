#include <iostream>
#include "Cerealpack.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Cerealpack packOfFlakes(8.0, 3.0, 10.0, "Cornflakes");

	cout << "packOfFlakes volume is " << packOfFlakes.Carton::volume() << endl;
	cout << "packOfFlakes weight is "
		 << packOfFlakes.Carton::getWeight() + packOfFlakes.Contents::getWeight() << endl;

	return 0;
}
