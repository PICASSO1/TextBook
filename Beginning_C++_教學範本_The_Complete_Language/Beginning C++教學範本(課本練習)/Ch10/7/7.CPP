#include <iostream>
#include <cassert>

using namespace std;

int main(void)
{
	int x(0), y(5);

	for(x=0; x,20; x++)
	{
		cout << "x = " << x << ", y = " << y << endl;
		assert(x<y); //
	}

	return 0;
}
