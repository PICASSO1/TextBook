#include <iostream>
#include "Time.H"
#define FileName "../../Time.TXT"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Time time;
	ifstream inFile;
	inFile.open(FileName, ios::in);
	if(inFile.is_open() == false)
		cout << "Error!! " << endl;
	else
		inFile >> time;
	inFile.close();
	inFile.clear();
	cout << time;

	return 0;
}
