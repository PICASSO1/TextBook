#include <iostream>

using namespace std;

int main(void)
{
	unsigned int k(430U);
	unsigned int i = (k >> 4) & ~(~0 << 3);

	cout << i << endl;

	return 0;
}
