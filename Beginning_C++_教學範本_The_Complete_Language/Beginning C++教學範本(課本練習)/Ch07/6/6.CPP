#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	const int max(100);
	long primes[max] = {2, 3, 5};
	int count(3);
	long trial(5);
	bool isprime(true);

	do
	{
		trial += 2;
		int i(0);

		do
		{
			isprime = trial % *(primes+i) >0;
		}while(++i < count && isprime);
		if(isprime)
			*(primes + count++) = trial;
	}while(count < max);
	for(int i(0); i<max; i++)
	{
		if(i%5 == 0)
			cout << endl;
		cout << setw(10) << *(primes+i);
	}
	cout << endl;

	return 0;
}
