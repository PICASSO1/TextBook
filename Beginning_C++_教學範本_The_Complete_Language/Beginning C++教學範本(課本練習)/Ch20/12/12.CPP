#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

template<typename Container, class Iter>void append(Container &C, Iter src, Iter src_end)
{
	copy(src, src_end, front_inserter(C));
}

int main(int argc, char *argv[], char *envp[])
{
	int A[] = {1, 9, 7, 5, 15};
	list<int> L;

	append(L, A, A + 5);
	copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
