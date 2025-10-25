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
//================================================================
int Sequence::Compare(Sequence SEQ)
{
	int nRet(0);

	if(this->nLen != SEQ.nLen)
		nRet = 1;
	else
	{
		for(int i(0); i<(this->nLen); i++)
		{
			if((this->nNum[i]) != SEQ.nNum[i])
				nRet = 2;
		}
	}

	return nRet;
}
