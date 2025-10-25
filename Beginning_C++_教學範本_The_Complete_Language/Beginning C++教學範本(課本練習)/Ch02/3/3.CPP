#include <iostream>

using namespace std;

int main(void)
{
	int apples=10, children=3;

	cout << "Each child gets "
		 << apples/children
		 << " fruits";

	cout << endl
	     << "We have "
		 << apples%children
		 << " left over."
		 << endl; //

	return 0;
}
