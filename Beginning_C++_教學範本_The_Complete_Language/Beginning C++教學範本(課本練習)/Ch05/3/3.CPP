#include <iostream>

using namespace std;

int main(void)
{
	int sum(0), count(0);

	cout << "How many integers do you want to sum?? ";
	cin >> count;

	for(int i(1); i<=count; i++)
		sum += i;
	cout << endl << "The sum of the integers from 1 to " << count << " is " << sum << endl;

	return 0;
}
