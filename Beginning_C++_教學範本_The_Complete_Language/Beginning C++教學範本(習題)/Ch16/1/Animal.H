#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string NAME = "Animal", size_t Weight = 1.0);
	virtual void who(void) const;
	virtual void sound(void) const = 0;
	virtual ~Animal(void);
protected:
	string strName;
	size_t nWeight;
};

#endif