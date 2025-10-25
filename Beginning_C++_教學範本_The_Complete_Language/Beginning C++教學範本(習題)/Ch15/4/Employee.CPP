#include <iostream>
#include "Employee.H"
#include <iomanip>

using namespace std;

Employee::Employee(size_t AGE, string NAME, string GENDER, int NUM)
{
//	cout << "Employee constructor!! " << endl;
	nAge = AGE;
	strName = NAME;
	strGender = GENDER;
	nNum = NUM;
}
//==========================================================================================
Employee::~Employee(void)
{
//	cout << "Employee Destructor!! " << endl;
}
//==========================================================================================
void Employee::Print(void)
{
	cout << "姓名: " << setw(10) << strName << ", 年齡: " << setw(2) << nAge
		 << ", 性別: " << setw(6) << strGender << ", 號碼: " << setw(8) << nNum << endl;
}
