#include <iostream>
#include <iomanip>

using namespace std;

inline int &smallest(int &a, int &b);
inline int &largest(int &c, int &d);

int main(void)
{
	int nNum1(0), nNum2(1), nNum3(0);

	for(int i(1); i<32; i++)
	{
		if(i == 1)
			cout << setw(10) << nNum1;
		else if(i == 2)
			cout << setw(10) << nNum2;
		else
		{
			nNum3 = smallest(nNum1, nNum2) + largest(nNum1, nNum2); // 用在這??
//			nNum3 = nNum1 + nNum2;
			cout << setw(10) << nNum3;
			nNum1 = largest(nNum1, nNum2);
			nNum2 = nNum3;
		}
		if(i%5 == 0)      // 換行用的!!
			cout << endl;
	}
	cout << endl;

	return 0;
}
//=================================================================
inline int &smallest(int &a, int &b)
{
	return a<b? a: b;
}
//=================================================================
inline int &largest(int &c, int &d)
{
	return c>d? c: d;
}
