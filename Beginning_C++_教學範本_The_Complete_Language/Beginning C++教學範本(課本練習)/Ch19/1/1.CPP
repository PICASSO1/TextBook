#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char argv[], char *envp[])
{
	const int max = 100;
	long primes[max] = {2, 3, 5};
	int count = 3;
	long trial = 5;
	bool isprime = true;

	do
	{
		trial += 2;      // trail = trail + 2;
		int i = 0;

		do
		{
			isprime = trial % *(primes + i) > 0;
		}while(++i < count && isprime);

		if(isprime)
			*(primes + count++) = trial;
	}while(count < max);

	ofstream outFile("../ABC.TXT");
	for(int i(0); i<max; i++)
	{
		if(i%5 == 0)
			outFile << endl;
		outFile << setw(10) << *(primes + i);
	}

	return 0;
}
