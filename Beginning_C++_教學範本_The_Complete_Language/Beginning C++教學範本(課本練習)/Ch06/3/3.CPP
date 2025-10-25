#include <iostream>

using namespace std;

int main(void)
{
	int values[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	cout << "There are " << sizeof(values)/sizeof(values[0]) << " elements in the array."
		 << endl;
	int sum(0);
	for(int i(0); i<sizeof(values)/sizeof(values[0]); sum+=values[i++])
		;
	cout << "The sum of the array elements is " << sum << endl;

	return 0;
}
