// 函數多載(Function Overloading)!!
#include <iostream>
#include <iomanip>

using namespace std;

double larger(double a, double b); // 第一個!!
long  larger(long a, long b);      // 第二個!!

int main(void)
{
	cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;   // 第一個!!
	cout << "Larger of 2.5 and 3.5 is " << larger(2.5f, 3.5f) << endl; // 第一個!!
	cout << "Larger of 15 and 25 is " << larger(15L, 25L) << endl;     // 第二個!!

	return 0;
}
//=========================================================================================
double larger(double a, double b)
{
	return a>b? a:b;
}
//=========================================================================================
long larger(long a, long b)
{
	return a>b? a:b;
}