#include <iostream>

using namespace std;

int main(void)
{
	int age(0), income(0), balance(0);

	cout << "Please enter your age in years: ";
	cin >> age;
	cout << "Please enter your annual income in dollars: ";
	cin >> income;
	cout << "What's your current account balance in dollars: ";
	cin >> balance;

	if(age>=21 && (income>25000 || (balance>100000)))
	{
		int loan(0);
		if(2*income < balance/2)
			loan=2*income;
		else
			loan=balance/2;
		cout << "You can borrow up to $" << loan << endl;
	}
	else
		cout << "Sorry, we're out of cash today!! " << endl;

	return 0;
}
