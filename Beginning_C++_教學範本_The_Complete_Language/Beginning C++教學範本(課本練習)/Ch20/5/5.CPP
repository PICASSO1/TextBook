#include <iostream>
#include <iterator>

using namespace std;

template<typename Iter>double average(Iter a, Iter end)
{
	double sum = 0.0;
	int count = 0;
	for(; a != end; ++count)
		sum += *a++;

	return sum / count;
}

int main(int argc, char *argv[], char *envp[])
{
	cout << "Enter some real numbers separated by whitepace - spaces, " << endl;
	cout << "tabs or newline. Then press the special key sequence " << endl;
	cout << "that marks the end-of-file(Ctrl + Z on a PC)" << endl;

	double av = average(istream_iterator<double>(cin), istream_iterator<double>());
	cout << "The average values is " << av << endl;

	return 0;
}

