#include <iostream>
#include <string>

namespace std
{
	extern size_t nTimes;      // 在std的名稱空間下，參考在別的*CPP檔案中的變數nTimes!!
	void Print(const string &s)
	{
		extern size_t nTimes;

		cout << s << endl;
		nTimes++;

		return;
	}
}
