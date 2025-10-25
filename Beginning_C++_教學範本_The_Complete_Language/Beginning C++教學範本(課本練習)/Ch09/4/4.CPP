#include <iostream>
#include <iomanip>

using namespace std;

template<class T>T larger(T a, T b);
template<>long *larger<long *>(long *a, long *b);

int main(void)
{
	cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;
	cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << endl;

	int value1(35), value2(45);

	cout << "Larger of " << value1 << " and " << value2 << " is " << larger(value1, value2) << endl;

	long a(9), b(8);

	cout << "Larger of " << a << " and " << b << " is " << larger(a, b) << endl;
	cout << "Larger of " << a << " and " << b << " is " << *larger(&a, &b) << endl; // New!!

	return 0;
}
//===========================================================================
template<class T>T larger(T a, T b)
{
	cout << "Stander Version" << endl;

	return a>b? a: b;
}
//===========================================================================
template<>long *larger<long *>(long *a, long*b)
{
	cout << "Specialized Version" << endl;

	return *a>*b? a: b;
}
