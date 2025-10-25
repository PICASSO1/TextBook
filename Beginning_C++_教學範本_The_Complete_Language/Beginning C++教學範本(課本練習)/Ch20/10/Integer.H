#ifndef INTEGER_H
#define INTEGER_H

using namespace std;

class Integer
{
private:
	int X;
public:
	Integer(int x = 0);
	Integer(const Integer &INT);
	~Integer(void);
	Integer &operator=(const Integer &INT);
	bool operator==(const Integer &INT) const;
	bool operator!=(const Integer &INT) const;
	bool operator<(const Integer &INT) const;
	int operator*(void) const;
	int operator[](int n) const;
	Integer &operator++(void);	
	Integer &operator--(void);
	Integer &operator++(int);
	Integer &operator--(int);
	Integer operator+(int n);
	Integer operator-(int n);
};

#endif