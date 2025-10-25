#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string Name = "Animal", double WEIGHT = 0.0);
protected:
	string strName;
	double nWeight;
	void who(void);
};

#endif