#include <iostream>
#include <string>
#include <cstring>
#define SIZE 81

using namespace std;
/*
void Change(char *STRING);

int main(void)
{
	char strTemp[SIZE];

	memset(strTemp, '\0', sizeof(strTemp));

	cout << "請隨便輸入一個字串: ";
	cin.getline(strTemp, SIZE, '\n');
	Change(strTemp);
	cout << "反向輸出的結果為: " << strTemp << endl;

	return 0;
}
//===================================================================
void Change(char *STRING)
{
	size_t nLen(0);
	char strTemp[SIZE];

	memset(strTemp, '\0', sizeof(strTemp));

	nLen = strlen(STRING);
	for(int i(nLen-1), j(0); (i>=0)&&(j<nLen); i--, j++)
		strTemp[j] = STRING[i];
	strcpy(STRING, strTemp);

	return;
}
*/

void Change(string STRING, char *FUCK);

int main(void)
{
	string strTemp;
	char strFuck[SIZE];

	memset(strFuck, '\0', sizeof(strFuck));

	cout << "請隨便輸入一個字串: ";
	getline(cin, strTemp, '\n');
	Change(strTemp, strFuck);
	cout << "反向輸出的結果為: " << strFuck << endl;

	return 0;
}
//===================================================================
void Change(string STRING, char *FUCK)
{
	size_t nLen(STRING.length());
	char strTemp[SIZE];

	memset(strTemp, '\0', sizeof(strTemp));

	for(int i(nLen-1), j(0); (i>=0)&&(j<nLen); i--, j++)
		strTemp[j] = STRING[i];
	strcpy(FUCK, strTemp);

	return;
}
