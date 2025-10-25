#include <iostream>

using namespace std;

int larger(int &, int &);

int main(void)
{
	int value1(10), value2(20);

	cout << larger(value1, value2) << endl;

	return 0;
}
//==============================================================
int larger(int &m, int &n)
{
	return m>n? m: n;
}
