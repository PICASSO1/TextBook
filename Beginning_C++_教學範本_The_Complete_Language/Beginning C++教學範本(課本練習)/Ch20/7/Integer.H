#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <fstream>

using namespace std;

class Integer
{
private:
	int X;
public:
	Integer(int arg = 0);
	Integer(const Integer &INT); //
	bool operator!=(const Integer &arg) const;
	int operator*(void) const;
	Integer &operator++(void);
	bool operator<(const Integer &INT) const; //
	friend ostream &operator<<(ostream &out, const Integer &INT); //
	inline int getInt(void) const //
	{
		return X;
	}
};

#endif