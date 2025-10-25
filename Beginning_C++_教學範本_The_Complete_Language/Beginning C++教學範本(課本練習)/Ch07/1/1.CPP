#include <iostream>

using namespace std;

int main(void)
{
	long number(50L);
	long *pnumber=NULL;
	pnumber=&number;

	cout << "The value stored in the variable number is " << *pnumber << endl;

	return 0;
}
