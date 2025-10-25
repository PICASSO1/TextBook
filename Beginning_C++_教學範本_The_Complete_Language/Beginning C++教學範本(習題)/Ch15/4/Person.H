#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
	Person(size_t AGE = 16, string NAME = "NoName", string GENDER = "Male");
	~Person(void);
	void Print(void);
protected:
	size_t nAge;
	string strName;
	string strGender;
};

#endif