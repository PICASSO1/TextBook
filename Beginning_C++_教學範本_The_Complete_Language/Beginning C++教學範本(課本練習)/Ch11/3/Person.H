#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

struct Name
{
	char firstname[80];
	char surname[80];

	void show(void)
	{
		cout << firstname << " " << surname;
	}
};

struct Date
{
	int day;
	int month;
	int year;

	void show(void)
	{
		cout << month << "/" << day << "/" << year;
	}
};

struct Phone
{
	int areacode;
	int number;

	void show(void)
	{
		cout << areacode << " " << number;
	}
};

struct Person
{
	struct Name name;
	struct Date birthdate;
	struct Phone number;

	void show(void)
	{
		name.show();
		cout << endl;
		cout << "Born: ";
		birthdate.show();
		cout << endl;
		cout << "Telephone: ";
		number.show();
		cout << endl;
	}

	int age(struct Date &date)
	{
		if(date.year <= birthdate.year)
			return 0;

		int years = date.year - birthdate.year;
		if((date.month > birthdate.month) || (date.month == birthdate.month && date.day >= birthdate.day))
			return years;
		else
			return --years;
	}
};

#endif