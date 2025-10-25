#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.H"

using namespace std;

class Sheep: public Animal
{
public:
	Sheep(string NAME = "Sheep", size_t Weight = 2.0);
	virtual void sound(void) const;
	~Sheep(void);
};

#endif