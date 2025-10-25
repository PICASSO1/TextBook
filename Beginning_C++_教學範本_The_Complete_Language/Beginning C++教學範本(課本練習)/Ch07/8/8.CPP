#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int max(0), count(3);
	long trail(5);
	bool isprime(true);

	cout << "Enter the number of primes you would like: ";
	cin >> max;
	long *primes=NULL; //
	primes=new long[max];
	*primes=2;
	*(primes+1)=3;
	*(primes+2)=5;
	do
	{
		trail+=2;
		int i(0);

		do
		{
			isprime=trail % *(primes+i) >0;
		}while(++i < count && isprime);
		if(isprime)
			*(primes + count++)=trail;
	}while(count < max);
	for(int i(0); i<max; i++)
	{
		if(i%5==0)
			cout << endl;
		cout << setw(10) << *(primes+i);
	}
	cout << endl;
	delete []primes;
	primes=NULL;

	return 0;
}
