#include <iostream>
#include <iterator>
#include <algorithm>
#include "Integer.H"

using namespace std;

#include <utility>

using namespace std::rel_ops;


int main(void)
{
	Integer F1(-1), L1(10);
	cout << "The values [-1..10) in forward order: " << endl;
	copy(F1, L1, ostream_iterator<int>(cout, " "));
	cout << endl;

	typedef reverse_iterator<Integer> CountDown; //??
	CountDown F2(10), L2(-1);
	cout << "the values (10..-1] in reverse order: " << endl;
	copy(F2, L2, ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}

