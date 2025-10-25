#include <iostream>

using namespace std;

inline void throwIt(int i);

int main(int argc, char *argv[], char *envp[])
{
	for(int i(0); i<=5; i++)
	{
		try
		{
			cout << endl << "outer try1: ";
			if(i == 0)
				throw i;
			if(i == 1)
				throwIt(i);
			try
			{
				cout << endl << "inner try: ";
				if(i == 2)
					throw static_cast<long>(i);
				if(i == 3)
					throwIt(i);
			}
			catch(int n)
			{
				cout << endl << "Catch int for inner try." << "Exception " << n;
			}
			cout << endl << "outer try2: ";
			if(i == 4)
				throw i;
			throwIt(i);
		}
		catch(int n)
		{
			cout << endl << "Catch int for outer try. " << "Exception " << n;
		}
		catch(long n)
		{
			cout << endl << "Catch long for outer try. " << "Exception " << n;
		}
		cout << endl;
	}

	return 0;
}
//=====================================================================
void throwIt(int i)
{
	throw i;
}
