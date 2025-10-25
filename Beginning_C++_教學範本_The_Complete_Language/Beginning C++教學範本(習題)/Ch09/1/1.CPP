#include <iostream>
#include <string>

using namespace std;

int plus(int a, int b);
double plus(double a, double b);
string plus(string str1, string str2);

int main(void)
{
	cout << "這是一支簡單的函數多載練習!! " << endl;
	cout << "int n = plus(3, 4) = " << plus(3, 4) << endl;
	cout << "double d = plus(3.2, 4.2) = " << plus(3.2, 4.2) << endl;
	cout << "string s = plus(\"Hel\", \"lo!! \") = " << plus("Hel", "lo!! ") << endl;

	string s1("aaa"), s2("bbb");
	cout << "string s3 = plus(s1, s2) = " << plus(s1, s2) << endl;

	return 0;
}
//==========================================================================
int plus(int a, int b)
{
	return a+b;
}
//==========================================================================
double plus(double a, double b)
{
	return a+b;
}
//==========================================================================
string plus(string str1, string str2)
{
	return str1+str2;
}
