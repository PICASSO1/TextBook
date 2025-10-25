#include <iostream>
#include "Time.H"
#define FileName "../Time.TXT"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Time time(23, 54, 21);
	cout << time;

	ofstream outFile;
	outFile.open(FileName, ios::out);
	if(outFile.is_open() == false)
		cout << "Error!! " << endl;
	else
		outFile << time;
	outFile.close();
	outFile.clear();

	return 0;
}
