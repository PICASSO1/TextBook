#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string strTemp1, strTemp2;
	size_t nLen(0U);

	cout << "這支程式會判斷您所輸入的兩個字串是否回文(什麼是回文啊)!! " << endl;
	cout << "請輸入第一個字串: ";
	cin >> strTemp1;
	cout << "請輸入第二個字串: ";
	cin >> strTemp2;
	nLen = strTemp1.length();
	for(size_t i(0U); i<nLen; i++)
	{
		size_t j(0U);
		while(strTemp2[j]!='\0')
		{
			if(strTemp1.compare(i, 1, strTemp2, j, 1)==0)
			{
				strTemp2.erase(j, 1);
				j=0;
			}
			else
				j++;
		}
	}
	if(strTemp2[0]=='\0')
		cout << "字串1與字串2互相回文!! " << endl;
	else
	{
		cout << "字串1: " << strTemp1 << endl;
		cout << "字串2: " << strTemp2 << endl;
		cout << "沒有回文!! " << endl;
	}

	return 0;
}
