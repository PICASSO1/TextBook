#ifndef BOXPTR_H
#define BOXPTR_H
#include "List.H"

using namespace std;

class BoxPtr
{
private:
	Box *pBox;
	TruckLoad &rLoad;
	BoxPtr(void);
	BoxPtr(BoxPtr &);
	BoxPtr &operator=(const BoxPtr &);

public:
	BoxPtr(TruckLoad &load);         // Constructor
	Box &operator*(void) const;
	Box *operator->(void) const;
	Box *operator++(void);
	const Box *operator++(int);
	operator bool(void);
};

#endif