#include <iostream>
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
