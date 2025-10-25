#include <iostream>
#include "FunC.H"
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

long nextprime(long lastprime, const char *FILE)
{
	bool isprime = false;
	long aprime = 0;
	ifstream inFile(FILE);

	if(inFile.is_open() == false)
	{
		throw ios::failure(string("Error open out put file ") + string(FILE) + string(" in nextprime() "));
//		throw ios::fail(string("Error open out put file ") + string(ABC) + string(" in nextprime() "));
	}

	for(;;)
	{
		lastprime += 2;
		long limit = static_cast<long>(sqrt(lastprime));
		do
		{
			inFile >> aprime;
		}while(aprime <= limit && inFile.eof() != true && (isprime = lastprime % aprime > 0));
		if(!isprime)
		{
			inFile.close();
			return lastprime;
		}
		inFile.seekg(0);
	}
}
