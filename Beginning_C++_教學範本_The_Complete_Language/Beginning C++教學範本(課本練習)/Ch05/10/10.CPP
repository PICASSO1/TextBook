#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main(void)
{
	int table(0);
	const int table_min(1), table_max(12), input_tries(3);
	char ch('\0');

	do
	{
		for(int count(1); ; count++)
		{
			cout << "What size table would you like(" << table_min << " to "
				 << table_max << "): ";
			cin >> table;
			
			if(table>=table_min && table<=table_max)
				break;
			else if(count < input_tries)
				cout << "Invalid input - Try again." << endl;
			else
			{
				cout << "Invalid table size entered - for the third times." << endl
					 << "Sorry, only three goes - program terminated." << endl;
				exit(1);
			}
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
