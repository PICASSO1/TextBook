#ifndef INTEGER_H
#define INTEGER_H

using namespace std;

class Integer
{
private:
	int X;
public:
	Integer(int arg = 0);
	bool operator!=(const Integer &arg) const;
	int operator*(void) const;
	Integer &operator++(void);
	const Integer operator++(int);
};

#endif