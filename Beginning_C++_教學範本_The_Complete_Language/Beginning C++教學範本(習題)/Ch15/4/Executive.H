#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Employee.H"

using namespace std;

class Executive: public Employee
{
private:
	char cKey;
public:
	Executive(size_t AGE = 40, string NAME = "Executive", string GENDER = "YYYYYY", int NUM = 99999999, char KEY = 'N');
	~Executive(void);
	void Print(void);
	char getKey(void);
};

#endif