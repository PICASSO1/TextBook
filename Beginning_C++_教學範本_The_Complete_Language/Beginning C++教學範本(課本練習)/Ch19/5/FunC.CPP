#include <iostream>
#include "FunC.H"
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

long nextprime(long lastprime, const char *filename)
{
	bool isprime = false;
	long aprime = 0;
	ifstream inFile;

	for(;;)
	{
		lastprime += 2;
		long limit = static_cast<long>(sqrt(lastprime));
		inFile.open(filename, ios::in | ios::binary);
		if(inFile.is_open() == false)
			throw ios::failure(string("Error opening input file ") + string(filename) + string(" in nextprime!! "));
		do
		{
			read(inFile, aprime);
		}while(aprime <= limit && inFile.eof() != true && (isprime = lastprime % aprime > 0));
		inFile.close();
		if(isprime)
		{
			return lastprime;
		}
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
