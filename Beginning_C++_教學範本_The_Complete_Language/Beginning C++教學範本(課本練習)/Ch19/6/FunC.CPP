#include <iostream>
#include "FunC.H"
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

long nextprime(fstream &primes)
{
	bool isprime = false;
	long aprime = 0, candidate = 0;
	primes.seekg(-static_cast<int>(2 * sizeof(long)), ios::end);
	read(primes, candidate);

	for(;;)
	{
		candidate += 2;
		long limit = sqrt(candidate);
		primes.seekg(0, ios::beg);
		do
		{
			read(primes, aprime);
		}while(aprime <= limit && (isprime = candidate % aprime > 0));
		if(isprime)
			return candidate;
	}
}
//===============================================================================================
void read(istream &in, long &value)
{
	in.read(reinterpret_cast<char *>(&value), sizeof(value));
}
//===============================================================================================
void write(ostream &out, long value)
{
	out.write(reinterpret_cast<char *>(&value), sizeof(value));
}
