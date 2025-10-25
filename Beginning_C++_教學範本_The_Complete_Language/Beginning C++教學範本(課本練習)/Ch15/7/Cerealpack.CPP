#include <iostream>
#include "Cerealpack.H"

using namespace std;

Cerealpack::Cerealpack(double length, double breadth, double height, const char *cerealType): Carton(length, breadth, height, "cardboard"), Contents(cerealType)
{
	cout << "Cerealpack Constructor!! " << endl;
	Contents::volume = 0.9 * Carton::volume();
}

Cerealpack::~Cerealpack(void)
{
	cout << "Cerealpack Destructor!! " << endl;
}
