#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<string, string> PAIR;
typedef map<PAIR, string> Directory;

int main(int argc, char *argv[], char *envp[])
{
	Directory PhoneBook;
	string strFirstName, strLastName, strNumber;
	cout << "輸入名字、姓氏，和電話號碼，藉由空白來分開。號碼能夠嵌入空白(# to exit): " << endl;
	while(1)
	{
		cin >> strFirstName;
		if(strFirstName[0] == '#')
			break;
		cin >> strLastName;
		cin >> strNumber;
		PhoneBook[make_pair(strFirstName,strLastName)] = strNumber;
	}
	Directory::iterator pNumber;
	cout << "從號碼簿取得電話號碼，請輸入名字和姓氏藉由空白來分開(# to exit): " << endl;
	while(1)
	{
		cin >> strFirstName;
		if(strFirstName[0] == '#')
			break;
		cin >> strLastName;
		pNumber = PhoneBook.find(make_pair(strFirstName,strLastName));
		if(pNumber == PhoneBook.end())
			cout << "沒找到喔!! " << endl;
		else
			cout << "號碼是: " << pNumber->second << endl;
	}
//	多加一個For Loop!!
	for(pNumber = PhoneBook.begin(); pNumber != PhoneBook.end(); pNumber++)
	{
		cout << setw(10) << pNumber->first.first << setw(10) << pNumber->first.second 
		     << setw(11) << pNumber->second << endl;
	}
	cout << "掰掰!! " << endl;
	
	return 0;
}
