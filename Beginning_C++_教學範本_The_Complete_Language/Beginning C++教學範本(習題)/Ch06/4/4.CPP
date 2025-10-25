#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string strOrignal("Now is the winter of our discontent.");
	string strReplaced("FOUND");
	string strTemp;

	cout << "Origna: " << strOrignal << endl;
	cout << "Please enter the word you want to replacement: ";
	cin >> strTemp;
	int nStart=strOrignal.find(strTemp);
	while(nStart!=string::npos)
	{
		strOrignal.replace(nStart, strTemp.length(), strReplaced);
		cout << "changed: " << strOrignal << endl << endl;
		strOrignal.replace(nStart, strReplaced.length(), strTemp);      // 取代回來!!
		cout << "changed: " << strOrignal << endl;
		cout << "Please enter the word you want to replacement: ";
		cin >> strTemp;
		nStart=strOrignal.find(strTemp);
	}
	cout << endl << "GAME OVER!! "<< endl;

	return 0;
}
