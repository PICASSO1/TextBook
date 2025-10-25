#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
void Show_Sequence(const int *first, const int *last)
{
	cout << "{ ";
	copy(first, last, ostream_iterator<int>(cout, " "));
	cout << " }" << endl;
}
*/
template<typename FwdIter>void Show_Sequence(FwdIter first, FwdIter last)
{
	cout << "{ ";
	copy(first, last, ostream_iterator<int>(cout, " "));
	cout << " }" << endl;
}

int main(int argc, char *argv[], char *envp[])
{
	int values[] = {11, 88, 99};
	vector<int> V(values, values + 3);

	Show_Sequence(V.begin(), V.end());
	Show_Sequence(V.rbegin(), V.rend());
	copy(V.rbegin(), V.rend(), ostream_iterator<int>(cout, ".0 "));
	cout << endl;

	return 0;
}
