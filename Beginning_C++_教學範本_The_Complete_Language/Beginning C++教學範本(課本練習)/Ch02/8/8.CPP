#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	float value1=0.1f;
	float value2=2.1f;
	value1-=0.09f;
	value2-=2.09f;

	cout << setprecision(14) << fixed << value1 - value2 << endl;
	cout << setprecision(5) << scientific << value1 - value2 << endl;

	return 0;
}
