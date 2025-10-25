#include <iostream>

using namespace std;

#include "Person.H"

int main(void)
{
	struct Person her = 
	{
		{"Pablo", "Picasso"},
		{1, 3, 1979},
		{02, 8879576}
	};
	struct Person actress = her;

	her.show();

	struct Date today = {23, 2, 2007};

	cout << "Today is ";
	today.show();
	cout << endl;
	cout << "Today " << actress.name.firstname << " is " << actress.age(today) << " years old. " << endl;

	return 0;
}
