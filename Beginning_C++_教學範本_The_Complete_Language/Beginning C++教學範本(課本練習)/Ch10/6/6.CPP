#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Another.H"
#define TESTINDEX

int random(int count);

int main(void)
{
	int a(10), b(5), result(0);

	int (*pfun[])(int, int) = {fun::sum, fun::product, fun::difference};
	int fcount(sizeof(pfun)/sizeof(pfun[0])), select(0);

	srand(static_cast<unsigned>(time(0)));
	for(int i(0); i<10; i++)
	{
		select = random(fcount);
#ifdef TESTINDEX
		cout << "Random number = " << select << endl;
		if((select >= fcount) || (select < 0))
		{
			cout << "Invalid array index = " << select << endl;

			return 1;
		}
#endif
		result = pfun[select](a, b);
		cout << "result = " << result << endl;
	}
	result = pfun[1](pfun[0](a, b), pfun[2](a, b));
	cout << endl << "The product of the sum and the difference = " << result << endl;

	return 0;
}
//===================================================================
int random(int count)
{
	return static_cast<int>((count * static_cast<long>(rand()))/(RAND_MAX+1));
}
