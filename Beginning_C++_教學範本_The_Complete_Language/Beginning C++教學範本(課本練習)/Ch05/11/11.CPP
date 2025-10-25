#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	char ch('\0');
	int count(0);
	double temperature(0.0), average(0.0);

	for(; ; )
	{
		cout << "Enter a value: ";
		cin >> temperature;
		average += temperature;
		count++;

		cout << "Do you want to enter another(y/n): ";
		cin >> ch;
		cout << endl;
		if(tolower(ch)=='n')
			break;
	}
	cout << "The average temperature is " << average/count << endl;

	return 0;
}
