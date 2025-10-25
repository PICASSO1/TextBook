#include <iostream>
#include <iomanip>
#include <fstream>
#define ABC "../ABC.TXT"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	ifstream inFile(ABC);
	if(inFile.is_open() == false)
	{
		cout << "Failed to open file!! " << endl;
		exit(1);
	}
	long aprime = 0;
	int count = 0;
	while(inFile.eof() == false)
	{
		inFile >> aprime;
		cout << (count++ % 5 == 0? "\n": "") << setw(10) << aprime;
	}
	cout << endl;

	return 0;
}
