#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename RndIter>double average(RndIter first, RndIter last)
{
	return accumulate(first, last, 0.0) / (last - first);
}

int main(int argc, char *argv[], char *envp[])
{
	vector<int> v(10, 1);
	partial_sum(v.begin(), v.end(), v.begin());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
	cout << "The average is " << average(v.begin(), v.end()) << endl;

	return 0;
}
