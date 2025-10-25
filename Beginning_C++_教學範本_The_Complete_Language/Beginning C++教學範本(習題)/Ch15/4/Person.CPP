#include "Person.H"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

Person::Person(size_t AGE, string NAME, string GENDER)
{
//	cout << "Person Constructor!! " << endl;
	nAge = AGE;
	strName = NAME;
	strGender = GENDER;
}
//==========================================================================================
Person::~Person(void)
{
//	cout << "Person Destructor!! " << endl;
}
//==========================================================================================
void Person::Print(void)
{
	cout << "Name: " << setw(10) << strName << ", Age: " << setw(2) << nAge
		 << ", SEX: " << setw(6) << strGender << endl;
}
//==========================================================================================
