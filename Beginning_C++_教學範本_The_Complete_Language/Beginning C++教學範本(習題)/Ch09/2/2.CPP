#include <iostream>
#include <string>

using namespace std;


template<class AUTO> AUTO plus(AUTO a, AUTO b);

int main(void)
{
	cout << "這是一支簡單的函數多載練習!! " << endl;
	cout << "int n = plus(3, 4) = " << plus(3, 4) << endl;
	cout << "double d = plus(3.2, 4.2) = " << plus(3.2, 4.2) << endl;
	cout << "string s = plus(\"Hel\", \"lo!! \") = " << plus(static_cast<string>("Hel"), static_cast<string>("lo!! ")) << endl;

	string s1("aaa"), s2("bbb");
	cout << "string s3 = plus(s1, s2) = " << plus(s1, s2) << endl;

	return 0;
}
//==========================================================================
template<class AUTO> AUTO plus(AUTO a, AUTO b)
{
	return a+b;
}
