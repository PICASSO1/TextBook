#ifndef DOG_H
#define DOG_H
#include "Animal.H"

using namespace std;

class Dog: public Animal
{
public:
	Dog(string NAME = "Dog", size_t Weight = 3.0);
	virtual void sound(void) const;
	~Dog(void);
};

#endif