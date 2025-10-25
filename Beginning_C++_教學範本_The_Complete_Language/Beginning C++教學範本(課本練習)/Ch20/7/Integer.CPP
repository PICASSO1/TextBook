#include <iostream>
#include "Integer.H"

using namespace std;

Integer::Integer(int arg)
{
//	cout << "Constructor!! " << endl;
	X = arg;
}
//=============================================================================================
Integer::Integer(const Integer &INT)
{
//	cout << "Copy Constructor!! " << endl;
	X = INT.X;
}
//=============================================================================================
bool Integer::operator !=(const Integer &arg) const
{
	if((this->X) == arg.X)
		cout << endl<< "operator != returns false " << endl;

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
bool Integer::operator <(const Integer &INT) const
{
	return (this->X) < (INT.X);
}
//=============================================================================================
ostream &operator<<(ostream &out, const Integer &INT)
{
	return out << INT.getInt();
}
