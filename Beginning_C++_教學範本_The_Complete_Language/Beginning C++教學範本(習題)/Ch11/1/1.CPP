#include <iostream>
#include "AUTO.H"

using namespace std;

int main(int argc, char *argv, char *envp)
{
	size_t nRet(0);

	cout << "這是一支可以轉換台幣和人民幣的匯率(4:1)程式!! \n" << endl;

	while(1)
	{
		nRet = Show();
		if(nRet == 1)
			Change(nRet);
		else // if(nRet == 2)
			Change(nRet);
	}

	return 0;
}

