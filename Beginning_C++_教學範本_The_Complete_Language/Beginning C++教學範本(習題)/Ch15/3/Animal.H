#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string Name = "Animal", double WEIGHT = 0.0);
	void who(void) const;
protected:
	string strName;
	double nWeight;
};

#endif