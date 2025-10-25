#include <iostream>
#include "MyTroubles.H"

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
			if(i < 3)
				throw trouble;
			if(i < 5)
				throw moreTrouble;
			else
				throw bigTrouble;
		}
		catch(BigTrouble &rT)
		{
			cout << "BigTrouble object caught: " << rT.what() << endl;
		}
		catch(MoreTrouble &rT)
		{
			cout << "MoreTrouble object caught: " << rT.what() << endl;
		}
		catch(Trouble &rT)
		{
			cout << "Trouble object caught: " << rT.what() << endl;
		}
		cout << "End of the for loop(after the catch blocks)- i is " << i << endl;
	}
	cout << endl;

	return 0;
}
