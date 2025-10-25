#include <iostream>
#include <cstring>
#define SIZE 81
#include "FunC.H"
#define FileName "../Text.TXT"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	char cKey = 0;
	char strTemp[SIZE];

	memset(strTemp, '\0', sizeof(char));

	cKey = Show();
	if(cKey == '1')
	{
		cout << endl << "請隨便輸入一串英文(含空白): ";
		cin.getline(strTemp, SIZE, '\n');
		UnSpace(strTemp);
		cout << strTemp << endl;
	}
	else if(cKey == '2')
	{
		ifstream inFile;
		inFile.open(FileName, ios::in);
		if(inFile.is_open() == false)
			cout << "Open input file error!! \a" << endl;
		else
		{
			cout << endl;
			while(inFile.eof() != true)
			{
				inFile.getline(strTemp, SIZE, '\n');
				UnSpace(strTemp);
				cout << strTemp << endl;
			}
		}
		inFile.close();
		inFile.clear();
	}
	else // if(cKey != 1 && cKey != 2)
		exit(0);

	return 0;
}
