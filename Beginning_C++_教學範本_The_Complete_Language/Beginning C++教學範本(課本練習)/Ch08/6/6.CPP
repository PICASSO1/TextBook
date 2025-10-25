#include <iostream>

using namespace std;

double yield(double values[][4], int n);

int main(void)
{
	double beans[3][4]=
	{
		{1.0, 2.0, 3.0, 4.0},
		{5.0, 6.0, 7.0, 8.0},
		{9.0, 10.0, 11.0, 12.0}
	};

	cout << "Yield = " << yield(beans, sizeof(beans)/sizeof(beans[0])) << endl;

	return 0;
}
//=================================================================
double yield(double values[][4], int n)
{
	double sum(0.0);

	for(int i(0); i<n; i++)
	{
		for(int j(0); j<4; j++)
			sum += values[i][j];
	}

	return sum;
}
