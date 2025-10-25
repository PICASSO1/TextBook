#include <iostream>
#include "Integer.H"

using namespace std;

Integer::Integer(int x)
{
//	cout << "Constructor!! " << endl;
	X = x;
}
//===============================================================================================
Integer::Integer(const Integer &INT)
{
//	cout << "Copy Constructor!! " << endl;
	X = INT.X;
}
//===============================================================================================
Integer::~Integer(void)
{
//	cout << "Destructor!! " << endl;
}
//===============================================================================================
Integer &Integer::operator =(const Integer &INT)
{
	(this->X) = INT.X;

	return *this;
}
//===============================================================================================
bool Integer::operator ==(const Integer &INT) const
{
	return (this->X) == INT.X;
}
//===============================================================================================
bool Integer::operator !=(const Integer &INT) const
{
	return (this->X) != INT.X;
}
//===============================================================================================
bool Integer::operator <(const Integer &INT) const
{
	return (this->X) < INT.X; 
}
//===============================================================================================
int Integer::operator *(void) const
{
	return (this->X);
}
//===============================================================================================
int Integer::operator [](int n) const
{
	return (this->X) + n;
}
//===============================================================================================
Integer &Integer::operator ++(void)
{
	++X;

	return *this;
}
//===============================================================================================
Integer &Integer::operator --(void)
{
	--X;

	return *this;
}
//===============================================================================================
Integer &Integer::operator ++(int)
{
//	Integer temp(*this);
	++(this->X);
	return *this;
}
//===============================================================================================
Integer &Integer::operator --(int)
{
//	Integer temp(*this);
	--(this->X);
	return *this;
}
//===============================================================================================
Integer Integer::operator +(int n)
{
	return Integer((this->X) + n);
}
//===============================================================================================
Integer Integer::operator -(int n)
{
	return Integer((this->X) - n);
}
