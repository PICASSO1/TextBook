#include <iostream>
#include "Executive.H"
#include <iomanip>

using namespace std;

Executive::Executive(size_t AGE, string NAME, string GENDER, int NUM, char KEY)
{
	nAge = AGE;
	strName = NAME;
	strGender = GENDER;
	nNum = NUM;
	cKey = KEY;
}
//==========================================================================================
Executive::~Executive(void)
{
//	cout << "Executive Destructor!! " << endl;
}
//==========================================================================================
void Executive::Print(void)
{
	cout << "Name: " << setw(10) << strName << ", Age: " << setw(2) << nAge
		 << ", SEX: " << setw(6) << strGender << ", No.: " << setw(8) << nNum
		 << ", Manager:"  << cKey << endl;
}
//==========================================================================================
char Executive::getKey(void)
{
	return cKey;
}
