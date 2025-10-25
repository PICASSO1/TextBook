#include <iostream>

using namespace std;

int main(void)
{
	int apple=10, orange=6, boys=3, girls=4;
	int fruit_per_chile=(apple+orange)/(boys+girls);

    cout << "Each child gets "
		 << fruit_per_chile
		 << " fruits."
		 << endl;

	return 0;
}
