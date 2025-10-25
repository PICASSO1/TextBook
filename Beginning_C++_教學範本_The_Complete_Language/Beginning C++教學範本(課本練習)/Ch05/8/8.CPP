#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	const int table_min(2), table_max(12);
	int table(0);
	char ch('\0');

	do
	{
		cout << "What size table would you like(" << table_min << " to " << table_max << "): ";
		cin >> table;

		if(table<table_min || table>table_max)
		{
			cout << "Invalid table size entered. Program terminated. " << endl;
			exit(1);
		}
		cout << "     |";
		for(int i(1); i<=table; i++)
			cout << " " << setw(3) << i << " |";
		cout << endl;

		for(int j(0); j<=table; j++)
			cout << "------";
		cout << endl;

		for(int k(1); k<=table; k++)
		{
			cout << " " << setw(3) << k << " |";
			for(int i(1); i<=table; i++)
				cout << " " << setw(3) << i*k << " |";
			cout << endl;
		}
		cout << endl << "Do you want another table(y/n)?? ";
		cin >> ch;
		cout << endl;
	}while(tolower(ch)=='y');

	return 0;
}
