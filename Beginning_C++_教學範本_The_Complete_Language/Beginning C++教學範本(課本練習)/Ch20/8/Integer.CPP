#include <iostream>
#include "Integer.H"

using namespace std;

Integer::Integer(int arg)
{
//	cout << "Constructor!! " << endl;
	X = arg;
}
//=============================================================================================
bool Integer::operator !=(const Integer &arg) const
{
	return (this->X) != arg.X;
}
//=============================================================================================
int Integer::operator *(void) const
{
	return X;
}
//=============================================================================================
Integer &Integer::operator ++(void)
{
	++X;

	return *this;
}
//=============================================================================================
const Integer Integer::operator++(int)
{
	Integer temp(*this);

	++X;

	return temp;
}
