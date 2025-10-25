#include <iostream>
#include <iomanip>

using namespace std;

long nextFib(void);

int main(void)
{
	cout << "The Fibonacci Series" << endl;
	for(int i(0); i<30; i++)
	{
		if(i%5 == 0)
			cout << endl;
		cout << setw(12) << nextFib();
	}
	cout << endl;

	return 0;
}
//=======================================================
long nextFib(void)
{
	static long last(0), lastButOne(1);
	long next(last + lastButOne);
	lastButOne = last;
	last = next;

	return last;
}
