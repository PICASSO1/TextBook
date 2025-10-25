#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showData(const double data[], int count=1, const string &title="Data Values", int width=10, int perLine=5);
double *largest(double data[], int count);
double *smallest(double data[], int count);

int main(void)
{
	double samples[]={11.0, 23.0, 13.0, 4.0, 57.0, 36.0, 317.0, 88.0, 9.0, 100.0, 121.0, 12.0};
	const int count(sizeof(samples)/sizeof(double));

	showData(samples, count, "Original Values");

	int min(*smallest(samples, count));  // Output: 4
	for(int i(0); i<count; i++)
		samples[i] -= min; // samples[i] = samples[i] - min;
//	samples[]={7.0, 19.0, 9.0, 0.0, 53.0, 32.0, 313.0, 84.0, 5.0, 96.0, 117.0, 8.0};
	int max(*largest(samples, count));  // Output: 313
	for(int j(0); j<count; j++)
		samples[j] /= max; // samples[i] = samples[i] / man;
	showData(samples, count, "Normalized Values", 12);

	return 0;
}
//==============================================================================================
double *largest(double data[], int count)
{
	int indexMax(0);
	for(int i(1); i<count; i++)
	{
		if(data[indexMax] < data[i])
			indexMax = i;
	}

	return &data[indexMax];
}
//==============================================================================================
double *smallest(double data[], int count)
{
	int indexMin(0);
	for(int i(1); i<count; i++)
	{
		if(data[indexMin] > data[i])
			indexMin = i;
	}

	return &data[indexMin];
}
//==============================================================================================
void showData(const double data[], int count, const string &title, int width, int perLine)
{
	cout << endl << title;
	for(int i(0); i<count; i++)
	{
		if(i%perLine == 0)
			cout << endl;
		cout << setw(width) << data[i];
	}
	cout << endl;

	return;
}
