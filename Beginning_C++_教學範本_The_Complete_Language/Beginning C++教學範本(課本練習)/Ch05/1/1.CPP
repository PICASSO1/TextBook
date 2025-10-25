#include <iostream>

using namespace std;

int main(void)
{
	int i(1), sum(0);

	while(i<=10)
	{
		cout << i << endl;
		sum += i++;
	}
	cout << "Sum is " << sum << endl;

	return 0;
}
