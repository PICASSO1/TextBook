#ifndef LION_H
#define LION_H
#include "Animal.H"

using namespace std;

class Lion: public Animal
{
public:
	Lion(string Name = "Lion", double WEIGHT = 1.0);
	void who(void) const;
};

#endif