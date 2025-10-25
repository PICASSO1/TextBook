#ifndef AARDVARK_H
#define AARDVARK_H
#include "Animal.H"

using namespace std;

class Aardvark: public Animal
{
public:
	Aardvark(string Name = "Aardvark", double WEIGHT = 2.0);
	void who(void) const;
};

#endif