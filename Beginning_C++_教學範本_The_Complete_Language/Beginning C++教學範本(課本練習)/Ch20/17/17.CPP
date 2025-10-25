#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef map<string, int> Collection;
typedef Collection::const_iterator WordIter;

const char *ptrStr =
"How much wood would a woodchuck chuck if a woodchuck "
"could chuck wood? A woodchuck would chuck as much wood "
"as a woodchuck could chuck if a woodchuck could chuck wood. ";

int main(int argc, char *argv[], char *envp[])
{
	Collection M;

	istringstream text(ptrStr);
	istream_iterator<string> begin(text);
	istream_iterator<string> end;

	for(; begin != end; ++begin)
		M[*begin]++;

	for(WordIter m = M.begin(); m != M.end(); ++m)
		cout << setw(10) << m->second << " " << m->first << endl;

	return 0;
}
