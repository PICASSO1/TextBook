#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.H"

using namespace std;

class Employee: public Person
{
public:
	Employee(size_t AGE = 28, string NAME = "Employee", string GENDER = "XXXXXX", int NUM = 00000000);
	~Employee(void);
	void Print(void);
protected:
	int nNum;
};

#endif
