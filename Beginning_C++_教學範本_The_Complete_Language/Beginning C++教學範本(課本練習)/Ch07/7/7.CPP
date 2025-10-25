#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main(void)
{
	const int table(12);
	long values[table][table]={0};

	for(int i(0); i<table; i++)
	{
		for(int j(0); j<table; j++)
			*(*(values+i)+j) = (i+1) * (j+1);
	}
	cout << "     |";
	for(int k(1); k<=table; k++)
		cout << " " << setw(3) << k << " |";
	cout << endl;
	for(int l(0); l<=table; l++)
		cout << "------";
	cout << endl;
	for(int m(0); m<table; m++)
	{
		cout << " " << setw(3) << m+1 << " |";
		for(int n(0); n<table; n++)
			cout << " " << setw(3) << values[m][n] << " |";
		cout << endl;
	}

	return 0;
}
