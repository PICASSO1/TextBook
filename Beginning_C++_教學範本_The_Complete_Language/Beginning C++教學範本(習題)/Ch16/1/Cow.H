#ifndef COW_H
#define COW_H
#include "Animal.H"

using namespace std;

class Cow: public Animal
{
public:
	Cow(string NAME = "Cow", size_t Weight = 4.0);
	virtual void sound(void) const;
	~Cow(void);
};

#endif