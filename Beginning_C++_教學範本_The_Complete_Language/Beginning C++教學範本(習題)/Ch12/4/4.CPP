#include <iostream>
#include "Sequence.H"
#include "FunC.H"

using namespace std;

int main(void)
{
	int nRet(0);

	Sequence SEQ1, SEQ2(6, 10), SEQ3(9, 3), SEQ4(9, 3);
	// SEQ1(0, 10);
	nRet = SEQ1.Compare(SEQ2);
	cout << "SEQ1©MSEQ2: "; Compare(nRet);
	
	nRet = SEQ2.Compare(SEQ3);
	cout << "SEQ2©MSEQ3: "; Compare(nRet);

	nRet = SEQ3.Compare(SEQ4);
	cout << "SEQ3©MSEQ4: "; Compare(nRet);

	return 0;
}
