#include <iostream>

using namespace std;

double squared(double x);
double cubed(double a);
double sumarray(double array[], int len, double (*ptr)(double));

int main(void)
{
	double array[]={1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
	int len(sizeof(array)/sizeof(double));

	cout << "Sum of squares = " << sumarray(array, len, squared) << endl;
	cout << "Sum of cubes = " << sumarray(array, len, cubed) << endl;

	return 0;
}
//==================================================================================
double squared(double x)
{
	return x*x;
}
//==================================================================================
double cubed(double x)
{
	return x*x*x;
}
//==================================================================================
double sumarray(double array[], int len, double (*ptr)(double))
{
	double total(0.0);

	for(int i(0); i<len; i++)
		total += ptr(array[i]);

	return total;
}