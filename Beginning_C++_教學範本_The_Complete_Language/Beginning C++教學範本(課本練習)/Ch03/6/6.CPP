#include <iostream>

using namespace std;

int main(void)
{
	int count1(10), count3(50);

	cout << "Value of outer count1 = " << count1 << endl;
	{
		int count1(20), count2(30);

		cout << "Value of inner count1 = " << count1 << endl;
		count1+=3;
		count3+=count2;
	}
	cout << "Value of outer count1 = " << count1 << endl;
	cout << "Value of outer count3 = " << count3 << endl;

	return 0;
}
