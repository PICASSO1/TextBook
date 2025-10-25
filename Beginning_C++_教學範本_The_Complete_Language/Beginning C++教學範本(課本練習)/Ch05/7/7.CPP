#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int count(0);

	cout << "What upper limit would you like?? ";
	cin >> count;

	cout << "integer" << "    sum" << "       factorial" << endl;
	for(long n(1L), sum(0L), factorial(1L); sum += n, factorial *= n, n<=count; n++)
		cout << setw(4) << n << "   " << setw(7) << sum << " " << setw(15) << factorial << endl;

	return 0;
}
