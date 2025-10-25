#include "Another.H"

double compare::max(const double *data, int size)
{
	double result(data[0]);

	for(int i(0); i<size; i++)
	{
		if(result < data[i])
			result = data[i];
	}

	return result;
}

double compare::min(const double *data, int size)
{
	double result(data[0]);

	for(int i(0); i<size; i++)
	{
		if(result > data[i])
			result = data[i];
	}

	return result;
}
