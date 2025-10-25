#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#define FileName "../ABC.TXT"
#include "FunC.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	try
	{
		fstream primes;
		primes.open(FileName, ios::in | ios::binary);
		long count = 0;

		if(!primes)
		{
			primes.clear();
			cout << "File doesn't exist - creating...." << endl;
			primes.open(FileName, ios::out | ios::binary);
			if(!primes)
				throw ios::failure(string("Failed to create output file ") + string(FileName) +string(" in main()!! "));

			write(primes, 2);
			write(primes, 3);
			write(primes, 5);
			write(primes, count = 3);
			primes.close();
			primes.open(FileName, ios::in | ios::out | ios::binary);
		}
		long nprime = 0, lastprime = 0;
		for(;;)
		{
			cout << "Which primes(e.g. enter 15 for the 15th prime, 0 to end)?: "<< endl;
			cin >> nprime;
			if(nprime <= 0)
				return 0;
			primes.seekg(-static_cast<int>(sizeof(long)), ios::end);
			read(primes, count);
			if(nprime <= count)
			{
				cout << "Prime in file ";
				primes.seekg((nprime-1)*sizeof(long), ios::beg);
				read(primes, lastprime);
			}
			else
			{
				while(count < nprime)
				{
					lastprime = nextprime(primes);
					primes.seekg(-static_cast<int>(sizeof(long)), ios::end);
					write(primes, lastprime);
					write(primes, ++count);
				}
			}
			cout << "The " << nprime << ((nprime%10 == 1)&&(nprime != 11)? "st ":
			                             (nprime%10 == 2)&&(nprime != 12)? "nd ":
										 (nprime%10 == 3)&&(nprime != 13)? "rd ": "th ") <<
				 "prime is " << lastprime << endl;
		}
		cout << endl;
	}
	catch(exception &EX)
	{
		cout << typeid(EX).name() << ": " << EX.what() << endl;
	}

	return 0;
}
