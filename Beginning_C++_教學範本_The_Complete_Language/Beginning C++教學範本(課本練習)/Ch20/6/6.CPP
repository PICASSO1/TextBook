#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

template<typename Iter>double average(Iter a, Iter end)
{
	double sum = 0.0;
	int count = 0;
	for(; a != end; count++)
		sum += *a++;

	return sum / count;
}

int main(int argc, char *argv[], char *envp[])
{
	char *stock_ticker = "4.5, 6.75, 8.25";
	istringstream ticker(stock_ticker);
	istream_iterator<double>begin(ticker);
	istream_iterator<double>end;

	cout << "Reading: " << stock_ticker << ". Today's average is ";
	cout << average(begin, end) << endl;

	return 0;
}
