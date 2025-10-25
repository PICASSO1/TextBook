#include <iostream>
#include <string>
#include "PrintThis.H"
#include "PrintThat.H"

namespace std
{
	size_t nTimes(0);      // 在std的名稱空間下，宣告一個全域變數nTimes!!
}

using namespace std;

int main(void)
{
	PrintThis("Hello!! ");
	PrintThat("World!! ");
	cout << "Print被呼叫了 " << nTimes << " 次!! " << endl;

	return 0;
}
