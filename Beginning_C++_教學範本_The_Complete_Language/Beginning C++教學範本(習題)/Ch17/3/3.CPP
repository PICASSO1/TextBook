#include <iostream>
#include <cstdlib>
#include "CurveBall.H"

using namespace std;

int random(int Count);
void Fuck(void) throw(CurveBall);      // 會丟出異常的函式!!
void MyHandler(void);

int main(int argc, char *argv[], char *envp[])
{
	int nRet = 1000, nCount = 0;
	TooManyException III;
	set_terminate(MyHandler);

	for(int i(0); i<nRet; i++)
	{
		try
		{
			Fuck();
		}
		catch(CurveBall curveball)
		{
			cout << curveball.what() << endl;
			nCount++;
			try
			{
				if(nCount > 10)
					throw III;
			}
			catch(TooManyException iii)
			{
				cout << III.what() << endl;
			}
		}
	}
	cout << endl << "CurveBall exception thrown " << nRet << " times out of " << nCount << ". "<< endl;

	return 0;
}
//================================================================
int random(int Count)
{
	int nTemp = 0;

	do
	{
		nTemp = static_cast<int>((Count * static_cast<long>(rand()))/(RAND_MAX+1));
//		cout << "F: nTemp = " << nTemp << endl;
	}while(nTemp > 20);

	return nTemp;
}
//================================================================
void Fuck(void) throw(CurveBall)
{
	CurveBall Temp;

	if(random(20) < 5)
		throw Temp;
}
//================================================================
void MyHandler(void)
{
	cout << "Termination Handler Called!! " << endl;
	exit(1);
}
