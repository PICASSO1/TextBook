#include <iostream>
#include "MyTroubles.H"
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Trouble trouble;
	MoreTrouble moreTrouble;
	BigTrouble bigTrouble;

	for(int i(0); i<7; i++)
	{
		try
		{
			try
			{
				if(i<3)
					throw trouble;
				if(i<5)
					throw moreTrouble;
				else
					throw bigTrouble;
			}
			catch(...)      // 抓到所有的異常!!
			{
				cout << "We caught something! Let's rethrow it. " << endl;
				throw;
			}
		}
		catch(Trouble &rT)
		{
			cout << typeid(rT).name() << "object caught: " << rT.what() << endl;
		}
		cout << "End of the for loop (after the catch blocks) - is " << i << endl;
	}
	cout << endl;

	return 0;
}
