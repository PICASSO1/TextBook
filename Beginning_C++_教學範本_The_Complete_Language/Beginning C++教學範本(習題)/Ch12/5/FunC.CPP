#include <iostream>
#include "Sequence.H"
#include "FunC.H"

using namespace std;

void Compare(int RET)
{
	if(RET == 1)
		cout << "長度不同!! " << endl;
	else if(RET == 2)
		cout << "對應值不同!! " << endl;
	else // if(RET == 0)
		cout << "完全相同!! " << endl;

	return;
}
//============================================================
int Compare(Sequence SEQ1, Sequence SEQ2)
{
	int nRet(0);

	if(SEQ1.nLen != SEQ2.nLen)
		nRet = 1;
	else
	{
		for(int i(0); i<(SEQ1.nLen); i++)
		{
			if((SEQ1.nNum[i]) != SEQ2.nNum[i])
				nRet = 2;
		}
	}

	return nRet;
}
