#include <iostream>
#include "MyTroubles.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	for(int i(0); i<2; i++)
	{
		try
		{
			if(i == 0)
				throw Trouble();
			else
				throw Trouble("Nobody knows the trouble I've seen....");
		}
		catch(const Trouble &T)
		{
			cout << "Exception: " << T.what() << endl;
		}
	}

	return 0;
}
