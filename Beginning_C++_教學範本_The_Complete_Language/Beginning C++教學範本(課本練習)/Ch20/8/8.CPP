#include <iostream>
#include "Integer.H"

using namespace std;

template<typename Iter>double average(Iter a, Iter end)
{
	double sum = 0.0;
	int count =0;

	for(; a != end; ++count)
		sum += *a++;

	return sum / count;
}

int main(int argc, char *argv[], char *envp[])
{
	Integer first(1), last(11);

	cout << "The average of the integers from " << *first << " to " << -1 + *last;
	cout << " is " << average(first, last) << endl;

	return 0;
}

