#include <iostream>

using namespace std;

int main(void)
{
	char ch('\0');
	int count(0);
	double temperature(0.0), average(0.0);

	do
	{
		cout << "Enter a temperature reading: ";
		cin >> temperature;

		average += temperature;
		count++;

		cout << "Do you want to enter another?? (y/n): ";
		cin >> ch;
		cout << endl;
	}while(ch=='y');
	average /= count;
	cout << "Average temperature is " << average << endl;

	return 0;
}
