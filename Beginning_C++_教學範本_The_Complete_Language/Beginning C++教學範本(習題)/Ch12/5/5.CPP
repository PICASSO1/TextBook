#include <iostream>
#include "Sequence.H"
#include "FunC.H"

using namespace std;

int main(void)
{
	int nRet(0);

	Sequence SEQ1, SEQ2(8, 10), SEQ3(3, 2), SEQ4(3, 2);
	// SEQ1(0, 10);
	nRet = Compare(SEQ1, SEQ2);
	cout << "SEQ1©MSEQ2: "; Compare(nRet);
	
	nRet = Compare(SEQ2, SEQ3);
	cout << "SEQ2©MSEQ3: "; Compare(nRet);

	nRet = Compare(SEQ3, SEQ4);
	cout << "SEQ3©MSEQ4: "; Compare(nRet);

	return 0;
}
