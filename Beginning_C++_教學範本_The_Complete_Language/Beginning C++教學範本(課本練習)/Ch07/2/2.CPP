#include <iostream>

using namespace std;

int main(void)
{
	long *pnumber=NULL;
	long number1(55L), number2(99L);

	pnumber = &number1;
	*pnumber+=11;
	cout << "number1 = " << number1;
	cout << " &pnumbe1 = " << pnumber << endl;

	pnumber = &number2;
	number1 = *pnumber * 10;
	cout << "number1 = " << number1;
	cout << " pnumber = " << pnumber;
	cout << " *pnumber = " << *pnumber << endl;

	return 0;
}
