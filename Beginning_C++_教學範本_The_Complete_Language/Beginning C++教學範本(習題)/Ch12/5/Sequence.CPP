#include <iostream>
#include "Sequence.H"

using namespace std;

void Sequence::Print(int LEN, int NUM[])
{
	for(int n(0); n<LEN; n++)
	{
		cout << "nNum[" << n << "] = " << NUM[n] << endl;
	}
	cout << endl;

	return;
}
