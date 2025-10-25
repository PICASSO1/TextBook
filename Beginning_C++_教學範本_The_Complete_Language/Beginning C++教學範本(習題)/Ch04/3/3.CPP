#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void Convert(char KEY);

int main(void)
{
	char cKey('\0');

	cout << "請隨便輸入一個字元: ";
	cin >> cKey;

	if(isalpha(cKey))
		Convert(cKey);
	else
		cout << "輸入的不是字母!! " << endl;
	cout << "程式結束!! " << endl;

	return 0;
}
//=====================================================================
void Convert(char KEY)
{
	int a, nKey=static_cast<int>(KEY);
	char strTemp[9];

	memset(strTemp, 0, sizeof(strTemp));

	sprintf(strTemp, "%X", nKey);
	for(a=0; a<2; a++)
	{
		switch(strTemp[a])
		{
		    case '0': cout << "0000"; break;
			case '1': cout << "0001"; break;
		    case '2': cout << "0010"; break;
			case '3': cout << "0011"; break;
		    case '4': cout << "0100"; break;
			case '5': cout << "0101"; break;
		    case '6': cout << "0110"; break;
			case '7': cout << "0111"; break;
		    case '8': cout << "1000"; break;
			case '9': cout << "1001"; break;
		    case 'A': cout << "1010"; break;
			case 'B': cout << "1011"; break;
		    case 'C': cout << "1100"; break;
			case 'D': cout << "1101"; break;
		    case 'E': cout << "1110"; break;
			case 'F': cout << "1111"; break;
		}
	}
	cout << endl;

	return;
}
